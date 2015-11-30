
#include "hadoop_streaming.h"
#include "stringsplit.h"
#include <stdlib.h>
#include <sstream>
#include <string>
#include <fstream>
using namespace std;

using hadoop_streaming::Mapper;
using hadoop_streaming::ReduceInputIterator;
using hadoop_streaming::Reducer;

class FaceCalReducer : public Reducer {
 public:
  
  virtual void Reduce(ReduceInputIterator* inputs) {
  
  for(;!inputs->Done();inputs->Next())
 {
  size_t pos = inputs->value().find("@");
  string imagename = inputs->value().substr(0,pos);
  string matvalue = inputs->value().substr(pos+1); 
  OutputFile(imagename,matvalue);
 }
}
};

int main(int argc, char** argv) {
  FaceCalReducer reducer;
  ReduceWorker(&cin, &reducer);
  return 0;
}
