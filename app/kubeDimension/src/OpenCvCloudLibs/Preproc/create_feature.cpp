#include <stdio.h>
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include <stdlib.h>
#include "opencv2/core/core.hpp"
#include "opencv2/flann/miniflann.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/video/video.hpp"
#include "opencv2/features2d/features2d.hpp"
#include "opencv2/objdetect/objdetect.hpp"
#include "opencv2/calib3d/calib3d.hpp"
#include "opencv2/ml/ml.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/contrib/contrib.hpp"
#include "opencv2/objdetect/objdetect.hpp"
#include "opencv2/opencv.hpp"
using namespace cv;
using namespace std;

void load(const string &file_name,cv::PCA &pca_)
{
    FileStorage fs(file_name,FileStorage::READ);
    fs["mean"] >> pca_.mean ;
    fs["e_vectors"] >> pca_.eigenvectors ;
    fs["e_values"] >> pca_.eigenvalues ;
    fs.release();

}

void getFilename(const string &path,string &filename, string &type){
  int slapos = path.find_last_of("/");
  filename = path.substr(slapos+1, path.size()-slapos);
  int dotpos = filename.find_last_of(".");
  type = filename.substr(dotpos+1, filename.size() - dotpos);
  filename = filename.substr(0, dotpos);
}

string int2string(const int& num)
{
  ostringstream oss;
  oss << num;
  return oss.str();
}

string loadImage(const string& filestring)
{
    int nEigens = 50;    // number of eigenvalues
    PCA pca_analysis;
    load("/mirror/PCA.xml",pca_analysis);

    IplImage * pInpImg =  cvLoadImage(filestring.c_str(), CV_LOAD_IMAGE_COLOR);

    string filename;
	string type;
    getFilename(filestring,filename,type);
    string face_cascade_name = "/mirror/haarcascade_frontalface_alt.xml";
    CascadeClassifier pCascade;
    pCascade.load(face_cascade_name); 
    IplImage *tmp;

    // detect faces in image
    std::vector<Rect> faces;
    pCascade.detectMultiScale( pInpImg, faces, 1.1, 3, 0|CV_HAAR_SCALE_IMAGE, Size(0, 0) );
    if(faces.size()==0)
	return "";

    	int i =0;

		int x1 = (faces[i].x - 0.2*faces[i].width)>=0?(faces[i].x - 0.2*faces[i].width):0;
		int y1 = (faces[i].y - 0.5*faces[i].height)>=0?(faces[i].y - 0.5*faces[i].height):0;
		int x2 = (faces[i].x + 1.2*faces[i].width)<=pInpImg->width?(faces[i].x + 1.2*faces[i].width):pInpImg->width;
		int y2 = (faces[i].y + 1.5*faces[i].height)<=pInpImg->height?(faces[i].y + 1.5*faces[i].height):pInpImg->height;

        CvPoint pt1 = { x1 , y1 };
		CvPoint pt2 = { x2 , y2 };
        //cvRectangle(pInpImg, pt1, pt2, CV_RGB(0,255,0), 3, 4, 0);

		cvSetImageROI(pInpImg, cvRect(x1, y1, x2-x1, y2-y1));
		tmp = cvCreateImage(cvGetSize(pInpImg),
                               pInpImg->depth,
                               pInpImg->nChannels);

		cvCopy(pInpImg, tmp, NULL);

		Mat mat_img(tmp);
		Mat faceImgArr;
		resize(mat_img,faceImgArr,Size(240,300),0,0,CV_INTER_LINEAR);

	//start PCA
    int size = faceImgArr.cols * faceImgArr.rows;
    Mat mat(size, 1 ,CV_8UC1);

    faceImgArr.reshape(1, size).col(0).convertTo(mat, 0);    

    Mat temp_mat = pca_analysis.project(mat);

       string  s="";
        for(int row = 0; row<50;row++)
        {

          s += int2string((int)*(temp_mat.data + temp_mat.step[0] * row ));
  	  s += " ";
        }
	return s;
}

