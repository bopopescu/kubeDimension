#ifndef HADOOP_STREAMING_H
#define HADOOP_STREAMING_H

#endif // HADOOP_STREAMING_H

#include <iostream>
#include <string>


namespace hadoop_streaming {

using namespace std;


extern const char kKeyValueDelimitor;

class Mapper {
 public:
  Mapper() {}
  virtual ~Mapper() {}

  virtual void Start() {}
  virtual void Map(const string& key, const string& value);
  virtual void Flush() {}

 protected:
  void Output(const string& key, const string& value);
  void OutputWithSecondaryKey(const string& key, const string& secondary_key,
                              const string& value);

};


class ReduceInputIterator {
 public:
  enum State {
    UNINITIALIZED,
    IN_AN_INPUT,
    FINISHED_AN_INPUT,
    END_OF_SHARD
  };

  ReduceInputIterator(istream* input_stream)
      : state_(UNINITIALIZED),
        input_stream_(input_stream) {}

  void Next();
  void DiscardRemainingValues();

  bool Done() const { return state_ == FINISHED_AN_INPUT || state_ == END_OF_SHARD; }
  bool EOS() const  { return state_ == END_OF_SHARD; }

  const string& key() const;
  const string& secondary_key() const;
  const string& value() const;

 private:
  State state_;
  string key_, secondary_key_, value_;
  string next_key_;
  istream* input_stream_;

  bool FetchValue(string* key, string* secondary_key, string* value);
};

class Reducer {
 public:
  Reducer() {}
  virtual ~Reducer() {}

  virtual void Start() {}
  virtual void Reduce(ReduceInputIterator* reduce_inputs);
  virtual void Flush() {}

 protected:
 void OutputFile(const string& key, const string& value);
 void Output(const string& key, const string& value);
};

void MapWorker(istream* input_stream, Mapper* mapper);
void ReduceWorker(istream* input_stream, Reducer* reducer);

}
