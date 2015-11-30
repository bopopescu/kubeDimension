
#include "hadoop_streaming.h"
#include "stringsplit.h"
#include <stdlib.h>
#include <sstream>
#include <string>
using namespace std;

using hadoop_streaming::Mapper;
using hadoop_streaming::ReduceInputIterator;
using hadoop_streaming::Reducer;

class  FaceCalReducer : public Reducer {
 public:
  virtual void Reduce(ReduceInputIterator* inputs) {
    double maxValue = 0;
    string imagename = "";
   for (; !inputs->Done(); inputs->Next())
   {
	int pos = inputs->value().find(",");
	string name = inputs->value().substr(0,pos);
	string similarity = inputs->value().substr(pos+1);
        if(maxValue < atof(similarity.c_str()))
	{
	  maxValue = atof(similarity.c_str());
	  imagename = name;
	}
    }
    if ((maxValue/1000)>1)
	maxValue = 1000/maxValue;
    else maxValue = maxValue/1000;
    stringstream strs;
    strs << maxValue;
    Output(imagename,strs.str());
  }
};

int main(int argc, char** argv) {
  FaceCalReducer reducer;
  ReduceWorker(&cin, &reducer);
  return 0;
}
