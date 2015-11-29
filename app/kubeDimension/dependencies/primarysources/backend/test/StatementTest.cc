// Copyright 2015 Google Inc. All Rights Reserved.
// Author: Sebastian Schaffert <schaffert@google.com>
#include "gtest.h"
#include "Statement.h"

TEST(ValueTest, Equality) {
    // entity values
    Value entity1("Q123"), entity2("Q123"), entity3("Q124");

    ASSERT_EQ(entity1, entity2);
    ASSERT_NE(entity1, entity3);

    // string values
    Value str1("xxx", "en"), str2("xxx", "en"), str3("xxx", "fr"), str4("yyy", "en");

    ASSERT_EQ(str1, str2);
    ASSERT_NE(str1, str3);
    ASSERT_NE(str1, str4);

    // quantity values
    Value q1(Quantity(1.0)), q2(Quantity(1.0)), q3(Quantity(1.1));

    ASSERT_EQ(q1, q2);
    ASSERT_NE(q1, q3);

    // location values
    Value l1(47.11, 11.47), l2(47.11, 11.47), l3(48.12, 11.47);

    ASSERT_EQ(l1, l2);
    ASSERT_NE(l1, l3);

    // time values
    Time tv1(1923, 1, 1);
    tv1.precision = 11;
    Time tv2(1923, 1, 2);
    tv2.precision = 11;
    Time tv3 = tv1;
    tv3.precision = 9;

    Value t1(tv1), t2(tv1);

    Value t3(tv2), t4(tv3);

    ASSERT_EQ(t1, t2);
    ASSERT_NE(t1, t3);
    ASSERT_NE(t1, t4);
}

TEST(ValueTest, getQuantityAsString) {
    Value q1(Quantity("100000000000000000000")), q2(Quantity("-0.000001"));

    ASSERT_EQ(q1.getQuantityAsString(), "+100000000000000000000");
    ASSERT_EQ(q2.getQuantityAsString(), "-0.000001");
}

TEST(ValueTest, Serialize) {
    cppcms::archive archive;

    Value entity1("Q123");
    entity1.save(archive);

    Value entity2;
    archive.mode(cppcms::archive::load_from_archive);
    entity2.load(archive);

    ASSERT_EQ(entity1, entity2);
}

TEST(PropertyValueTest, Equality) {
    PropertyValue pv1("P123", Value("Q123")), pv2("P123", Value("Q123"));
    PropertyValue pv3("P123", Value("Q123","en"));
    PropertyValue pv4("P234", Value("Q123"));

    ASSERT_EQ(pv1, pv2);
    ASSERT_NE(pv1, pv3);
    ASSERT_NE(pv1, pv4);
}

TEST(PropertyValueTest, Serialize) {
    cppcms::archive archive;

    PropertyValue pv1("P123", Value("Q123"));
    pv1.save(archive);

    PropertyValue pv2;
    archive.mode(cppcms::archive::load_from_archive);
    pv2.load(archive);

    ASSERT_EQ(pv1, pv2);
}

TEST(StatementTest, Equality) {
    Statement s1("Q123", PropertyValue("P123", Value("Q321")));
    Statement s2("Q123", PropertyValue("P123", Value("Q321")));
    Statement s3("Q124", PropertyValue("P123", Value("Q321")));
    Statement s4("Q123", PropertyValue("P124", Value("Q321")));
    Statement s5("Q123", PropertyValue("P123", Value("Q421")));

    ASSERT_EQ(s1, s2);
    ASSERT_NE(s1, s3);
    ASSERT_NE(s1, s4);
    ASSERT_NE(s1, s5);
}

TEST(StatementTest, Serialize) {
    cppcms::archive archive;

    Statement s1("Q123", PropertyValue("P123", Value("Q321")));
    s1.save(archive);

    Statement s2;
    archive.mode(cppcms::archive::load_from_archive);
    s2.load(archive);

    ASSERT_EQ(s1, s2);
}
