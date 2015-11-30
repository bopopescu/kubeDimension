#include <stdlib.h>
#include <vector>
#include <string>
#include "stringsplit.h"
#include "hadoop_streaming.h"
#include <sstream>
#include <fstream>
#include <iostream>
#include "/usr/local/include/opencv2/core/core_c.h"
#include "/usr/local/include/opencv2/core/core.hpp"

using namespace std;
using namespace cv;
using hadoop_streaming::Mapper;
using hadoop_streaming::ReduceInputIterator;
using hadoop_streaming::Reducer;


class FaceCalMapper : public Mapper {
 public:
  cv::Mat imagefromPath; 
 
   FaceCalMapper(){
   imagefromPath = Mat(50,1,CV_8UC1);
   string temp_value;
   vector<string> temp_tokens;
   ifstream myfile ("~/compare.txt");
   if (myfile.is_open())
   {
     getline(myfile, temp_value);
     size_t position = temp_value.find(",");
     string compare_imagename = temp_value.substr(0,position);
     string compare_matrixvalue = temp_value.substr(position+1);
     SplitStringUsing(compare_matrixvalue," ",&temp_tokens);
     for(int i = 0;i < temp_tokens.size(); ++i)
     {
       *(imagefromPath.data + imagefromPath.step[0] * i ) = atoi(temp_tokens[i].c_str());
      }
   }
   myfile.close(); 
   }

  virtual void Map(const string& key, const string& value) {
    vector<string> matvalue;
    size_t pos = value.find(",");
    string imagename = value.substr(0,pos);
    string matrixvalue = value.substr(pos+1);

    cv::Mat imagefromDB(50,1,CV_8UC1);

    double difference;
    SplitStringUsing(matrixvalue," ",&matvalue);

    for(int i = 0;i < matvalue.size(); ++i)
    {
        *(imagefromDB.data + imagefromDB.step[0] * i ) = atoi(matvalue[i].c_str());
    }
    //compare two mat to get value
    difference = cv::norm(imagefromDB, imagefromPath);
    stringstream strs;
    strs << difference;
    string output1 = imagename + "," +strs.str();
    Output("compare",output1); 
 }
};


int main(int argc, char** argv) {
  FaceCalMapper mapper;
  MapWorker(&cin, &mapper);
  return 0;
}



