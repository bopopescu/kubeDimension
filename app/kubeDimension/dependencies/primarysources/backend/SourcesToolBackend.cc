// Copyright 2015 Google Inc. All Rights Reserved.
// Author: Sebastian Schaffert <schaffert@google.com>

#include "SourcesToolBackend.h"

#include <boost/iostreams/filtering_streambuf.hpp>
#include <boost/iostreams/copy.hpp>
#include <boost/iostreams/filter/gzip.hpp>
#include <chrono>

#include "Parser.h"

#include "Persistence.h"

int64_t SourcesToolBackend::cacheHits = 0;
int64_t SourcesToolBackend::cacheMisses = 0;

// Create cache key for an entity and dataset; the cache key is used to cache
// all statements of the given dataset having the entity as subject. If dataset
// is "", the cache key refers to all statements and the dataset name "all" will
// be used.
std::string createCacheKey(const std::string& qid, ApprovalState state, const std::string& dataset) {
    if (dataset == "") {
        return "ALL-" + qid + "-" + stateToString(state);
    } else {
        return qid + "-" + dataset + "-" + stateToString(state);;
    }
}

namespace cppcms {
    template<>
    struct serialization_traits<std::vector<Statement>> {
        ///
        /// Convert string to object
        ///
        static void load(std::string const &serialized_object,std::vector<Statement> &real_object)
        {
            archive a;
            a.str(serialized_object);
            cppcms::details::archive_load_container<std::vector<Statement>>(real_object, a);
        }
        ///
        /// Convert object to string
        ///
        static void save(std::vector<Statement> const &real_object,std::string &serialized_object)
        {
            archive a;
            cppcms::details::archive_save_container<std::vector<Statement>>(real_object, a);
            serialized_object = a.str();
        }
    };

    template<>
        struct serialization_traits<std::vector<std::string>> {
            ///
            /// Convert string to object
            ///
            static void load(std::string const &serialized_object,std::vector<std::string> &real_object)
            {
                archive a;
                a.str(serialized_object);
                cppcms::details::archive_load_container<std::vector<std::string>>(real_object, a);
            }
            ///
            /// Convert object to string
            ///
            static void save(std::vector<std::string> const &real_object,std::string &serialized_object)
            {
                archive a;
                cppcms::details::archive_save_container<std::vector<std::string>>(real_object, a);
                serialized_object = a.str();
            }
        };
} /* cppcms */

SourcesToolBackend::SourcesToolBackend(const cppcms::json::value& config) {
    connstr = build_connection(config);
}


std::vector<Statement> SourcesToolBackend::getStatementsByQID(
        cache_t &cache, const std::string &qid,
        ApprovalState state, const std::string &dataset){
    std::vector<Statement> statements;
    std::string cacheKey = createCacheKey(qid,state,dataset);

    // look up in cache and only hit backend in case of a cache miss
    if(!cache.fetch_data(cacheKey, statements)) {
        cppdb::session sql(connstr); // released when sql is destroyed

        Persistence p(sql);
        statements = p.getStatementsByQID(qid, state, dataset);
        cache.store_data(cacheKey, statements, 3600);

        cacheMisses++;
    } else {
        cacheHits++;
    }

    return statements;
}

std::vector<Statement> SourcesToolBackend::getRandomStatements(
        cache_t &cache, int count, ApprovalState state) {
    cppdb::session sql(connstr); // released when sql is destroyed

    Persistence p(sql);
    return p.getRandomStatements(count, state);
}

std::vector<Statement> SourcesToolBackend::getAllStatements(
        cache_t& cache, int offset, int limit,
        ApprovalState state,
        const std::string& dataset,
        const std::string& property,
        const std::shared_ptr<Value> value) {
    cppdb::session sql(connstr); // released when sql is destroyed

    Persistence p(sql);
    return p.getAllStatements(offset, limit, state, dataset, property, value);
}

Statement SourcesToolBackend::getStatementByID(cache_t& cache, int64_t id) {
    cppdb::session sql(connstr); // released when sql is destroyed

    Persistence p(sql);
    return p.getStatement(id);
}

void SourcesToolBackend::updateStatement(
        cache_t& cache, int64_t id, ApprovalState state, const std::string& user) {
    cppdb::session sql(connstr); // released when sql is destroyed

    Persistence p(sql, true);
    sql.begin();

    try {
        // make sure statement exists; will throw an exception if not
        Statement st = p.getStatement(id);

        p.updateStatement(id, state);
        p.addUserlog(user, id, state);

        sql.commit();

        // update cache
        for (ApprovalState state : { APPROVED, UNAPPROVED, WRONG, DUPLICATE, BLACKLISTED }) {
            cache.rise(createCacheKey(st.getQID(), state, st.getDataset()));
            cache.rise(createCacheKey(st.getQID(), state, ""));
        }
        cache.rise("STATUS");
        cache.rise("ACTIVITIES");
    } catch (PersistenceException const &e) {
        sql.rollback();

        throw e;
    }

}

std::vector<Statement> SourcesToolBackend::getStatementsByRandomQID(
        cache_t& cache, ApprovalState state, const std::string& dataset) {
    cppdb::session sql(connstr); // released when sql is destroyed

    Persistence p(sql);
    std::string qid = p.getRandomQID(state, dataset);

    std::vector<Statement> statements;
    std::string cacheKey = qid + "-" + dataset;

    // look up in cache and only hit backend in case of a cache miss
    if(!cache.fetch_data(cacheKey, statements)) {
        cppdb::session sql(connstr); // released when sql is destroyed

        Persistence p(sql);
        statements = p.getStatementsByQID(qid, state, dataset);
        cache.store_data(cacheKey, statements, 3600);

        cacheMisses++;
    } else {
        cacheHits++;
    }

    return statements;
}

int64_t SourcesToolBackend::importStatements(cache_t& cache, std::istream &_in,
                                             const std::string& dataset, bool gzip, bool dedup) {
    // prepare GZIP input stream
    boost::iostreams::filtering_istreambuf zin;
    if (gzip) {
        zin.push(boost::iostreams::gzip_decompressor());
    }
    zin.push(_in);
    std::istream in(&zin);

    cppdb::session sql(connstr); // released when sql is destroyed

    sql.begin();
    Persistence p(sql, true);

    // get timestamp and use it as upload id
    int64_t upload = std::chrono::duration_cast<std::chrono::milliseconds>(
            std::chrono::system_clock::now().time_since_epoch()).count();

    int64_t count = 0, first_id = -1, current_id;
    Parser::parseTSV(dataset, upload, in, [&sql, &p, &count, &first_id, &current_id](Statement st)  {
        current_id = p.addStatement(st);

        // remember the ID of the first statement we add for deduplication
        if (first_id == -1) {
            first_id = current_id;
        }

        count++;

        // batch commit
        if(count % 100000 == 0) {
            sql.commit();
            sql.begin();
        }
    });
    sql.commit();

    if (dedup) {
        sql.begin();
        p.markDuplicates(first_id);
        sql.commit();
    }

    cache.clear();

    return count;
}

void SourcesToolBackend::deleteStatements(cache_t& cache, ApprovalState state) {
    cppdb::session sql(connstr); // released when sql is destroyed

    Persistence p(sql);
    p.deleteStatements(state);

    cache.clear();
}

Status SourcesToolBackend::getStatus(cache_t& cache) {
    Status result;

    if(!cache.fetch_data("STATUS", result)) {
        cppdb::session sql(connstr); // released when sql is destroyed

        Persistence p(sql, true);
        sql.begin();

        result.setStatements(p.countStatements());
        result.setApproved(p.countStatements(APPROVED));
        result.setUnapproved(p.countStatements(UNAPPROVED));
        result.setDuplicate(p.countStatements(DUPLICATE));
        result.setBlacklisted(p.countStatements(BLACKLISTED));
        result.setWrong(p.countStatements(WRONG));
        result.setTopUsers(p.getTopUsers(10));

        sql.commit();

        cache.store_data("STATUS", result, 3600);

        cacheMisses++;
    } else {
        cacheHits++;
    }
    return result;
}


Dashboard::ActivityLog SourcesToolBackend::getActivityLog(cache_t& cache) {

    Dashboard::ActivityLog result;

    if(!cache.fetch_data("ACTIVITIES", result)) {
        cppdb::session sql(connstr); // released when sql is destroyed
        Dashboard::Dashboard dashboard(sql);
        result = dashboard.getActivityLog(7, 12, 10);

        cache.store_data("ACTIVITIES", result, 3600);

        cacheMisses++;
    } else {
        cacheHits++;
    }

    return result;
}


std::vector<std::string> SourcesToolBackend::getDatasets(cache_t& cache) {
    std::vector<std::string> datasets;

    // look up in cache and only hit backend in case of a cache miss
    if(!cache.fetch_data("datasets", datasets)) {
        cppdb::session sql(connstr); // released when sql is destroyed

        Persistence p(sql);
        datasets = p.getDatasets();
        cache.store_data("datasets", datasets, 3600);

        cacheMisses++;
    } else {
        cacheHits++;
    }

    return datasets;
}
