/*

    kubeVision - OpenCV (part of the KubeVision)
    Modified by: Luc Michalski - 2015
    New features: Web-service and distributed search
    Based on: Find-Object - Mathieu Labbe - IntRoLab - Universite de Sherbrooke
    URL: https://github.com/introlab/find-object

*/

// Need to find some librairies up to date
// - http://openbiometrics.org/docs/
// - https://github.com/felixendres/rgbdslam_v2
// - https://gist.github.com/DevN00b1/63eba5813926e4d0ea32
// - https://github.com/royshil/CurveMatching

// Priorities:
// 1 - Fix homography crashes (proably Flann / Mini Flann, check also nanoflann)
// 2 - Reduce the size of vocabaulaires in memory (DBow2, Dlib)
// 3 - Implement color sift = https://github.com/eokeeffe/quasi_invariant-features (!!!!! sift with colours => priority)
//     - Rootsift
//     - ColorSift
// 4 - Implement Distributed Search 
// 5 - Implement Open Biometrics 

#include <cmath>
#include <vector>
#include <stdio.h>
#include <fstream>
#include <iostream>
#include <exception> // bad_alloc standard exception, Need to spread it everywhere where key processings happen

// Misc Libraries Headers
#include "utils/exif.h"
#include <libraw/libraw.h>

// OpenCV headers
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/calib3d/calib3d.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/opencv_modules.hpp>
#include <opencv2/imgcodecs.hpp>
#if CV_MAJOR_VERSION < 3
#include <opencv2/gpu/gpu.hpp>
#else
#include <opencv2/core/cuda.hpp>
#endif
#include <opencv/ml.h> // Let's see Dlib more in depth   

// QT 4.8 headers
#include <QtNetwork/QNetworkInterface>
#include <QtNetwork/QTcpSocket>
#include <QtCore/QCoreApplication>
#include <QtCore/QFile>
#include <QtCore/QFileInfo>
#include <QtCore/QTime>    

// PostHandler headers
#include "PostHandler.h"
#include <Tufao/HttpServerRequest>
#include <Tufao/Headers>
#include <opencv2/opencv.hpp>

// Find-Object headers
#include "find_object/JsonWriter.h"
#include "find_object/utilite/ULogger.h"
#include <jsoncpp/json/json.h>
#include "TcpResponse.h"

// Dlib Headers
#include <dlib/compress_stream.h>
#include <dlib/base64.h>
#include <dlib/image_io.h>
#include <dlib/image_transforms.h>

// RapidJson headers
#include "rapidjson/document.h"
#include "rapidjson/writer.h"
#include "rapidjson/stringbuffer.h"

// Add ETCD support for mapping ports/namespaces
//#include "services/Etcd.hpp"
//#include "services/RapidReply.hpp"

// Define Namespaces used
using namespace Tufao;
using namespace std;
using namespace cv;

const int kNewWidth = 320;
const int kNewHeight = 240;

// To clean up with the methods below
namespace util
{
    template < class T>
    void send_data(T & o, const std::vector<uchar> & v)
    {
        std::copy( v.begin(), v.end(), std::ostream_iterator<uchar>(o) );
    }

    void resize_coefs(const int original_w, const int original_h, int & new_w, int & new_h)
    {
        int num, den;
        if (new_w * original_h < new_h * original_w) {
            num = new_w;
            den = original_w;
        } else {
            num = new_h;
            den = original_h;
        }
        new_w = original_w * num / den;
        new_h = original_h * num / den;
    }
    vector<string> ReadAllLinesFromFile(const string& filename){
        ifstream file(filename);
        vector<string> fileNames;
        string temp;
        while(std::getline(file, temp)) {
            cout << temp << endl;
            const size_t found = temp.find_last_of("/\\");
            auto fileImg  = temp.substr(0,found) + "/" + temp.substr(found+1);
            fileNames.push_back(fileImg);
        }
        file.close();
        return fileNames;
    }
}

/*
* Scene Input/Output OpenCV-Based Processing <======= END
*/

int thresh = 50, N = 11;

/// perform the Simplest Color Balancing algorithm
void SimplestCB(const cv::Mat& in,const cv::Mat& out, float percent) {
    assert(in.channels() == 3);
    assert(percent > 0 && percent < 100);

    float half_percent = percent / 200.0f;

    vector<cv::Mat> tmpsplit; split(in,tmpsplit);
    for(int i=0;i<3;i++) {
        //find the low and high precentile values (based on the input percentile)
        cv::Mat flat; tmpsplit[i].reshape(1,1).copyTo(flat);
        cv::sort(flat,flat,CV_SORT_EVERY_ROW + CV_SORT_ASCENDING);
        int lowval = flat.at<uchar>(cvFloor(((float)flat.cols) * half_percent));
        int highval = flat.at<uchar>(cvCeil(((float)flat.cols) * (1.0 - half_percent)));
        cout << lowval << " " << highval << endl;
        
        //saturate below the low percentile and above the high percentile
        tmpsplit[i].setTo(lowval,tmpsplit[i] < lowval);
        tmpsplit[i].setTo(highval,tmpsplit[i] > highval);
        
        //scale the channel
        normalize(tmpsplit[i],tmpsplit[i],0,255,NORM_MINMAX);
    }
    merge(tmpsplit,out);
}

void sceneHeatmap(const cv::Mat& image, const std::string& fileNamePrefix) {

    /*
      cv::COLORMAP_AUTUMN = 0, 
      cv::COLORMAP_BONE = 1, 
      cv::COLORMAP_JET = 2, 
      cv::COLORMAP_WINTER = 3, 
      cv::COLORMAP_RAINBOW = 4, 
      cv::COLORMAP_OCEAN = 5, 
      cv::COLORMAP_SUMMER = 6, 
      cv::COLORMAP_SPRING = 7, 
      cv::COLORMAP_COOL = 8, 
      cv::COLORMAP_HSV = 9, 
      cv::COLORMAP_PINK = 10, 
      cv::COLORMAP_HOT = 11, 
      cv::COLORMAP_PARULA = 12 
    */
    cv::Mat imColor;
    if(image.channels() >= 3)
    {
        try {
            imColor = image;
            //cv::cvtColor(imColor, image, cv::COLOR_BGR2GRAY);   
            //GaussianBlur(imColor, imColor, cvSize(7,7), 1.5, 1.5);
            //threshold(imColor, imColor, 100, 255, CV_THRESH_BINARY);
            cv::subtract(cv::Scalar::all(255),imColor,imColor);
            imColor = cv::Scalar::all(190) - image;
        } catch(cv::Exception & e) {
            UERROR("cv::Scalar:all exception: %s. Maybe a problem with the type of the src matrix", e.what());
        } catch ( const std::exception& e ) {
            UERROR("cv::Scalar:all exception: %s. Maybe a problem with the type of the src matrix", e.what());
        }

        try {
            cv::applyColorMap(imColor, imColor, cv::COLORMAP_BONE);
        } catch(cv::Exception & e) {
            UERROR("cv::applyColorMap exception: %s. Maybe a problem with the type of the src matrix", e.what());
        } catch ( const std::exception& e ) {
            UERROR("cv::applyColorMap exception: %s. Maybe a problem with the type of the src matrix", e.what());
        }    
        imwrite( fileNamePrefix+"sceneHeatmap.jpg", imColor );
        imColor.copyTo(image);
    }

}

cv::Mat equalizeIntensity(const cv::Mat& image)
{
    if(image.channels() >= 3 || image.depth() != CV_8U) {
        cv::Mat ycrcb;

        cv::cvtColor(image,ycrcb,CV_BGR2YCrCb);

        std::vector<cv::Mat> channels;
        cv::split(ycrcb,channels);

        cv::equalizeHist(channels[0], channels[0]);

        cv::Mat result;
        cv::merge(channels,ycrcb);

        cv::cvtColor(ycrcb,result,CV_YCrCb2BGR);

        return result;
    }
    return cv::Mat();
}

void equalizeIntensity(const cv::Mat& image, const std::string& fileNamePrefix)
{
    cv::Mat result;
    if(image.channels() >= 3 || image.depth() != CV_8U) {
        cv::Mat ycrcb;

        try {
            cv::cvtColor(image,ycrcb,CV_BGR2YCrCb);
        } catch(cv::Exception & e) {
            UERROR("cv::cvtColor with CV_BGR2YCrCb for a matrix with %d channels, exception: %s. Maybe a problem with the type of the src matrix", image.channels(), e.what());
        } catch ( const std::exception& e ) {
           UERROR("cv::cvtColor with CV_BGR2YCrCb for a matrix with %d channels, exception: %s. Maybe a problem with the type of the src matrix", image.channels(), e.what());
        }

        std::vector<cv::Mat> channels;
        cv::split(ycrcb,channels);

        try {
            cv::equalizeHist(channels[0], channels[0]);
        } catch(cv::Exception & e) {
            UERROR("cv::equalizeHist with %d channels, exception: %s. Maybe a problem with the type of the src matrix", image.channels(), e.what());
        } catch ( const std::exception& e ) {
           UERROR("cv::equalizeHist with %d channels, exception: %s. Maybe a problem with the type of the src matrix", image.channels(), e.what());
        }

        cv::Mat result;
        cv::Mat copy;
        cv::merge(channels,ycrcb);

        try {
            cv::cvtColor(ycrcb,result,CV_YCrCb2BGR);
        } catch(cv::Exception & e) {
            UERROR("cv::cvtColor with CV_YCrCb2BGR for a matrix with %d channels, exception: %s. Maybe a problem with the type of the src matrix", image.channels(), e.what());
        } catch ( const std::exception& e ) {
           UERROR("cv::cvtColor with CV_YCrCb2BGR for a matrix with %d channels, exception: %s. Maybe a problem with the type of the src matrix", image.channels(), e.what());
        }

        try {
            fastNlMeansDenoisingColored(image, result, 10, 10);
        } catch(cv::Exception & e) {
            UERROR("cv::fastNlMeansDenoisingColored for a matrix with %d channels, exception: %s. Maybe a problem with the type of the src matrix", image.channels(), e.what());
        } catch ( const std::exception& e ) {
           UERROR("cv::fastNlMeansDenoisingColored for a matrix with %d channels, exception: %s. Maybe a problem with the type of the src matrix", image.channels(), e.what());
        }

        try {
            image.copyTo(copy);
            result.copyTo(image);
        } catch(cv::Exception & e) {
            UERROR("Error while copying the equalized image into the src; %s", e.what());
        } catch ( const std::exception& e ) {
            UERROR("Error while copying the equalized image into the src; %s", e.what());
        }

        try {
            imwrite( fileNamePrefix+"equalizeIntensity_non_equalized.jpg", copy );
        } catch(cv::Exception & e) {
            UERROR("Error while writing the equalizeIntensity copy file; %s", e.what());
        } catch ( const std::exception& e ) {
            UERROR("Error while writing the equalizeIntensity copy file; %s", e.what());
        }

        try {
            imwrite( fileNamePrefix+"equalizeIntensity_non_equalized.jpg", result );
        } catch(cv::Exception & e) {
            UERROR("Error while writing the equalizeIntensity result file; %s", e.what());
        } catch ( const std::exception& e ) {
            UERROR("Error while writing the equalizeIntensity result file; %s", e.what());
        }
    }

}

/*
void parallelogramRoi(const cv::Mat& src, const cv::Mat& dest, const cv::OutputArray ROI_Vertices) {

    cv::Size s = src.size();

    // ROI by creating mask for the parallelogram
    Mat mask = cvCreateMat(s.width, s.height, CV_8UC1);
    // Create black image with the same size as the original
    for(int i=0; i<mask.cols; i++)
       for(int j=0; j<mask.rows; j++)
           mask.at<uchar>(Point(i,j)) = 0;
     
    // Create Polygon from vertices
    vector<Point> ROI_Poly;
    approxPolyDP(ROI_Vertices, ROI_Poly, 1.0, true);
 
    // Fill polygon white
    fillConvexPoly(mask, &ROI_Poly[0], ROI_Poly.size(), 255, 8, 0);                 
 
    // Create new image for result storage
    Mat imageDest = cvCreateMat(s.width, s.height, CV_8UC3);
     
    // Cut out ROI and store it in imageDest
    image->copyTo(dest, mask);  

}
*/

bool isBorder(cv::Mat& edge, cv::Vec3b color)
{
    cv::Mat im = edge.clone().reshape(0,1);

    bool res = true;
    for (int i = 0; i < im.cols; ++i)
        res &= (color == im.at<cv::Vec3b>(0,i));

    return res;
}

/* 
 * Angle: 
 *  - finds a cosine of angle between vectors, from pt0->pt1 and from pt0->pt2
 */
double angle(cv::Point pt1, cv::Point pt2, cv::Point pt0)
{
    double dx1 = pt1.x - pt0.x;
    double dy1 = pt1.y - pt0.y;
    double dx2 = pt2.x - pt0.x;
    double dy2 = pt2.y - pt0.y;
    return (dx1*dx2 + dy1*dy2)/sqrt((dx1*dx1 + dy1*dy1)*(dx2*dx2 + dy2*dy2) + 1e-10);
}

void findSquares2(const cv::Mat& result, std::vector<std::vector<cv::Point> >& squares)
{
    cv::Mat image;    
    squares.clear();
    cv::Mat sharpen(result);
    medianBlur(result, sharpen, 1);
    //equalizeIntensity(result);
    image = result;
//    cv::cvtColor(result, image, cv::COLOR_BGR2GRAY);
    UINFO("Channels Matrix: %d", result.channels());
    UINFO("Depth Matrix: %s", result.depth());
    UINFO("Matrix Type: %s", result.type());

    cv::Mat pyr, timg, gray0(result.size(), CV_8U), gray;
    int thresh = 15, N = 11;
    cv::pyrDown(image, pyr, cv::Size(result.cols/2, result.rows/2));
    cv::pyrUp(pyr, timg, result.size());

    std::vector<std::vector<cv::Point> > contours;
    for( int c = 0; c < 3; c++ ) {
        int ch[] = {c, 0};
        mixChannels(&timg, 1, &gray0, 1, ch, 1);
        for( int l = 0; l < N; l++ ) {
            if( l == 0 ) {
                cv::Canny(gray0, gray, 0, thresh, 5);
                cv::dilate(gray, gray, cv::Mat(), cv::Point(-1,-1));
            }
            else {
                gray = gray0 >= (l+1)*255/N;
            }
            cv::findContours(gray, contours, CV_RETR_LIST, CV_CHAIN_APPROX_SIMPLE);
            std::vector<cv::Point> approx;
            for( size_t i = 0; i < contours.size(); i++ )
            {
                cv::approxPolyDP(cv::Mat(contours[i]), approx, arcLength(cv::Mat(contours[i]), true)*0.02, true);
                if( approx.size() == 4 && fabs(contourArea(cv::Mat(approx))) > 1000 && cv::isContourConvex(cv::Mat(approx))) {
                    double maxCosine = 0;

                    for( int j = 2; j < 5; j++ )
                    {
                        double cosine = fabs(angle(approx[j%4], approx[j-2], approx[j-1]));
                        maxCosine = MAX(maxCosine, cosine);
                    }

                    if( maxCosine < 0.3 ) {
                        squares.push_back(approx);
                    }
                }
            }
        }
    }
}

/* 
 * findSquares: 
 *  - returns sequence of squares detected on the image
 */
void findSquares(const cv::Mat& src, std::vector<std::vector<cv::Point> >& squares, const std::string& fileNamePrefix)
{
    cv::Mat src_gray;

    if(src.channels() >=3 || src.depth() != CV_8U) {
        cv::cvtColor(src, src_gray, cv::COLOR_BGR2GRAY);
    } else {
        src_gray = src;
    }

    cv::Mat filtered; // Blur helps to decrease the amount of detected edges
    try {
        cv::blur(src_gray, filtered, cv::Size(3, 3));
    } catch(cv::Exception & e) {
        UERROR("cv::blur exception: %s. Maybe a problem with the grayscale version of the src", e.what());
    } catch ( const std::exception& e ) {
        UERROR("cv::blur exception: %s. Maybe a problem with the grayscale version of the src", e.what());
    }

    // write a copy of this processing step: Blur effect
    try {
        cv::imwrite(fileNamePrefix+"_findSquares_out_blur.jpg", filtered);
    } catch(cv::Exception & e) {
        UERROR("cv::imwrite exception: %s. Maybe a problem while writing the findSquares out blur mask", e.what());
    } catch ( const std::exception& e ) {
        UERROR("cv::imwrite exception: %s. Maybe a problem while writing the findSquares out blur mask", e.what());
    }

    cv::Mat edges; // Detect edges
    int thresh = 128;
    try {
        cv::Canny(filtered, edges, thresh, thresh*2, 3);
    } catch(cv::Exception & e) {
        UERROR("cv::Canny exception: %s. Maybe a problem while applying the canny edge detector", e.what());
    } catch ( const std::exception& e ) {
        UERROR("cv::Canny exception: %s. Maybe a problem while applying the canny edge detector", e.what());
    }

    // write a copy of this processing step: Detect edges
    try {
        cv::imwrite(fileNamePrefix+"_findSquares_out_edges.jpg", edges);
    } catch(cv::Exception & e) {
        UERROR("cv::imwrite exception: %s. Maybe a problem while writing the findSquares out canny edge mask", e.what());
    } catch ( const std::exception& e ) {
        UERROR("cv::imwrite exception: %s. Maybe a problem while writing the findSquares out canny edge mask", e.what());
    }

    cv::Mat dilated_edges; // Dilate helps to connect nearby line segments
    try {
        cv::dilate(edges, dilated_edges, cv::Mat(), cv::Point(-1, -1), 2, 1, 1); // default 3x3 kernel
    } catch(cv::Exception & e) {
        UERROR("cv::dilate exception: %s. Maybe a problem while applying the dilate filter [imageProcessing]", e.what());
    } catch ( const std::exception& e ) {
        UERROR("cv::dilate exception: %s. Maybe a problem while applying the dilate filter [imageProcessing]", e.what());
    }

    // write a copy of this processing step: Dilate
    try {
        cv::imwrite(fileNamePrefix+"_findSquares_out_dilated.jpg", dilated_edges);
    } catch(cv::Exception & e) {
        UERROR("cv::imwrite exception: %s. Maybe a problem while writing the findSquares out canny edge mask", e.what());
    } catch ( const std::exception& e ) {
        UERROR("cv::imwrite exception: %s. Maybe a problem while writing the findSquares out canny edge mask", e.what());
    }

    std::vector<std::vector<cv::Point> > contours; // Find contours and store them in a list
    try {
        cv::findContours(dilated_edges, contours, cv::RETR_LIST, cv::CHAIN_APPROX_SIMPLE);
    } catch(cv::Exception & e) {
        UERROR("cv::findContours exception: %s. Maybe a problem with the dilated edge mask", e.what());
    } catch ( const std::exception& e ) {
        UERROR("cv::findContours exception: %s. Maybe a problem with the dilated edge mask", e.what());
    }

    // Test contours and assemble squares out of them
    std::vector<cv::Point> approx;
    for (size_t i = 0; i < contours.size(); i++)
    {
        // approximate contour with accuracy proportional to the contour perimeter
        cv::approxPolyDP(cv::Mat(contours[i]), approx, cv::arcLength(cv::Mat(contours[i]), true)*0.02, true);

        // Note: absolute value of an area is used because
        // area may be positive or negative - in accordance with the
        // contour orientation
        if (approx.size() == 4 && std::fabs(contourArea(cv::Mat(approx))) > 1000 &&
            cv::isContourConvex(cv::Mat(approx)))
        {
            double maxCosine = 0;
            for (int j = 2; j < 5; j++)
            {
                double cosine = std::fabs(angle(approx[j%4], approx[j-2], approx[j-1]));
                maxCosine = MAX(maxCosine, cosine);
            }

            if (maxCosine < 0.3) {
                squares.push_back(approx);
                UINFO("found a square, buddy !!!");
            }
        }
    }
}

/* 
 * rotationMatrix: 
 *  - rotate a matrix with a specified angle
 */
void rotationMatrix(double angle, const cv::Mat& src, const cv::Mat& dst) {
    // get rotation matrix for rotating the image around its center
    cv::Point2f center(src.cols/2.0, src.rows/2.0);
    cv::Mat rot;
    try {
        rot = cv::getRotationMatrix2D(center, angle, 1.0);
    } catch(cv::Exception & e) {
        UERROR("cv::getRotationMatrix2D exception: %s. Maybe a problem with the center calculation or the angle", e.what());
    } catch ( const std::exception& e ) {
        UERROR("cv::getRotationMatrix2D exception: %s. Maybe a problem with the center calculation or the angle", e.what());
    }

    // determine bounding rectangle
    cv::Rect bbox;
    try {
        bbox = cv::RotatedRect(center,src.size(), angle).boundingRect();
    } catch(cv::Exception & e) {
        UERROR("cv::RotatedRect exception: %s. Maybe some problems are related to the boundingRect or the source size", e.what());
    } catch ( const std::exception& e ) {
        UERROR("cv::RotatedRect exception: %s. Maybe some problems are related to the boundingRect or the source size", e.what());
    }

    // adjust transformation matrix
    rot.at<double>(0,2) += bbox.width/2.0 - center.x;
    rot.at<double>(1,2) += bbox.height/2.0 - center.y;

    try {
        cv::warpAffine(src, dst, rot, bbox.size());
    } catch(cv::Exception & e) {
        UERROR("cv::warpAffine exception: %s. Maybe some problems are related to the src, img or bounding box", e.what());
    } catch ( const std::exception& e ) {
        UERROR("cv::warpAffine exception: %s. Maybe some problems are related to the src, img or bounding box", e.what());
    }
}

/* 
 * findLargestSquare: 
 *  - find the largest square within a set of squares
 */
void findLargestSquare(const std::vector<std::vector<cv::Point> >& squares,
                       std::vector<cv::Point>& biggest_square)
{

    if (!squares.size()) {
        UINFO("findLargestSquare !!! No squares detect, nothing to do");
        return;
    }

    int max_width = 0;
    int max_height = 0;
    int max_square_idx = 0;
    for (size_t i = 0; i < squares.size(); i++)
    {
        cv::Rect rectangle;
        // Convert a set of 4 unordered Points into a meaningful cv::Rect structure.
        try {
            rectangle = cv::boundingRect(cv::Mat(squares[i]));
            UINFO("find_largest_square: #%d, rectangle x:%d, rectangle.y:%d, rectangle.width:%d, rectangle.height:%d ", i, rectangle.x, rectangle.y, rectangle.width, rectangle.height);
        } catch(cv::Exception & e) {
            UERROR("cv::drawContours exception: %s. Maybe the img is corrupted, so not able to draw contours", e.what());
        } catch ( const std::exception& e ) {
            UERROR("cv::drawContours exception: %s. Maybe the img is corrupted, so not able to draw contours", e.what());
        }

        // Store the index position of the biggest square found
        if ((rectangle.width >= max_width) && (rectangle.height >= max_height))
        {
            max_width = rectangle.width;
            max_height = rectangle.height;
            max_square_idx = i;
        }
    }

    biggest_square = squares[max_square_idx];

}

/* 
 * debugSquares (Deprecated soon): 
 *  - Find all squares in a picture and return a matrix (Should be converted to a void)
 */
cv::Mat debugSquares(std::vector<std::vector<cv::Point> >& squares, cv::Mat image)
{
    for( size_t i = 0; i< squares.size(); i++ ) {

        // draw contour
        try {
            cv::drawContours(image, squares, i, cv::Scalar(255,0,0), 1, 8, std::vector<cv::Vec4i>(), 0, cv::Point());
        } catch(cv::Exception & e) {
            UERROR("cv::drawContours exception: %s. Maybe the img is corrupted, so not able to draw contours", e.what());
        } catch ( const std::exception& e ) {
            UERROR("cv::drawContours exception: %s. Maybe the img is corrupted, so not able to draw contours", e.what());
        }

        // draw bounding rect
        cv::Rect rect;
        try {
            rect = boundingRect(cv::Mat(squares[i]));
        } catch(cv::Exception & e) {
            UERROR("cv::Rect on boundingRect exception: %s. Maybe the square matrix is corrupted", e.what());
        } catch ( const std::exception& e ) {
            UERROR("cv::Rect on boundingRect exception: %s. Maybe the square matrix is corrupted", e.what());
        }

        try {
            cv::rectangle(image, rect.tl(), rect.br(), cv::Scalar(0,255,0), 2, 8, 0);
        } catch(cv::Exception & e) {
            UERROR("cv::rectangle exception: %s. Maybe the img is corrupted, so not able to draw the rectangle", e.what());
        } catch ( const std::exception& e ) {
            UERROR("cv::rectangle exception: %s. Maybe the img is corrupted, so not able to draw the rectangle", e.what());
        }

        // draw rotated rect
        cv::RotatedRect minRect = minAreaRect(cv::Mat(squares[i]));
        cv::Point2f rect_points[4];
        minRect.points( rect_points );
        for ( int j = 0; j < 4; j++ ) {
            cv::line( image, rect_points[j], rect_points[(j+1)%4], cv::Scalar(0,0,255), 1, 8 ); // blue
        }
    }
    return image;
}

/* 
 * Autocrop: 
 *  - Auto-cropping image with arbitrary background color (Usually plain colors)
 */
void autocrop(cv::Mat& src, cv::Mat& dst)
{
    cv::Rect win(0, 0, src.cols, src.rows);

    std::vector<cv::Rect> edges;
    edges.push_back(cv::Rect(0, 0, src.cols, 1));
    edges.push_back(cv::Rect(src.cols-2, 0, 1, src.rows));
    edges.push_back(cv::Rect(0, src.rows-2, src.cols, 1));
    edges.push_back(cv::Rect(0, 0, 1, src.rows));

    cv::Mat edge;
    int nborder = 0;
    cv::Vec3b color = src.at<cv::Vec3b>(0,0);

    for(size_t i = 0; i < edges.size(); ++i)
    {
        edge = src(edges[i]);
        nborder += isBorder(edge, color);
    }

    if (nborder < 4)
    {
        src.copyTo(dst);
        return;
    }

    bool next;

    do {
        edge = src(cv::Rect(win.x, win.height-2, win.width, 1));
        if ((next = isBorder(edge, color)))
            win.height--;
    }
    while (next && win.height > 0);

    do {
        edge = src(cv::Rect(win.width-2, win.y, 1, win.height));
        if ((next = isBorder(edge, color)))
            win.width--;
    }
    while (next && win.width > 0);

    do {
        edge = src(cv::Rect(win.x, win.y, win.width, 1));
        if ((next = isBorder(edge, color)))
            win.y++, win.height--;
    }
    while (next && win.y <= src.rows);

    do {
        edge = src(cv::Rect(win.x, win.y, 1, win.height));
        if ((next = isBorder(edge, color)))
            win.x++, win.width--;
    }
    while (next && win.x <= src.cols);

    dst = src(win);
}

cv::Mat GetSquareImage( const cv::Mat& img, int target_width = 320 )
{
    int width = img.cols,
       height = img.rows;

    cv::Mat square;
    try {
        square = cv::Mat::zeros( target_width, target_width, img.type() );
    } catch(cv::Exception & e) {
        UERROR("cv::Mat::zeros exception: %s. Maybe could not get the type of the img", e.what());
    } catch ( const std::exception& e ) {
        // standard exceptions
        UERROR("cv::Mat::zeros exception: %s. Maybe could not get the type of the img", e.what());
    }

    int max_dim = ( width >= height ) ? width : height;
    float scale = ( ( float ) target_width ) / max_dim;

    cv::Rect roi;
    if ( width >= height )
    {
        roi.width = target_width;
        roi.x = 0;
        roi.height = height * scale;
        roi.y = ( target_width - roi.height ) / 2;
    }
    else
    {
        roi.y = 0;
        roi.height = target_width;
        roi.width = width * scale;
        roi.x = ( target_width - roi.width ) / 2;
    }

    try {
        cv::resize( img, square( roi ), roi.size() );
    } catch(cv::Exception & e) {
        UERROR("cv::resize exception: %s. Maybe the ig is corrupted to fit the roi", e.what());
    } catch ( const std::exception& e ) {
        // standard exceptions
        UERROR("cv::resize exception: %s.Maybe the ig is corrupted to fit the roi", e.what());
    }
    return square;
}

/* 
 * randomColor: 
 *  - pick a random color for plotting matches
 */
static cv::Scalar randomColor(cv::RNG& rng)
{
    int icolor = (unsigned)rng;
    return cv::Scalar(icolor&0xFF, (icolor>>8)&0xFF, (icolor>>16)&0xFF);
}

/* 
 * plotMatches: 
 *  - Display the plot matches between a input scene and pattern matched
 */
void plotMatches(const cv::Mat &srcColorImage, const cv::Mat &dstColorImage, vector<cv::Point2f> &srcPoints, vector<cv::Point2f> &dstPoints){
    
    // Create a image for displaying mathing keypoints
    cv::Size sz = cv::Size(srcColorImage.size().width + dstColorImage.size().width, srcColorImage.size().height + dstColorImage.size().height);
    cv::Mat matchingImage = cv::Mat::zeros(sz, CV_8UC3);
    
    // Draw camera frame
    cv::Mat roi1 = cv::Mat(matchingImage, cv::Rect(0, 0, srcColorImage.size().width, srcColorImage.size().height));
    srcColorImage.copyTo(roi1);
    // Draw original image
    cv::Mat roi2 = cv::Mat(matchingImage, cv::Rect(srcColorImage.size().width, srcColorImage.size().height, 
        dstColorImage.size().width, dstColorImage.size().height));
    dstColorImage.copyTo(roi2);

    cv::RNG rng(0xFFFFFFFF);
    // Draw line between nearest neighbor pairs
    for (int i = 0; i < (int)srcPoints.size(); ++i) {
        cv::Point2f pt1 = srcPoints[i];
        cv::Point2f pt2 = dstPoints[i];
        cv::Point2f from = pt1;
        cv::Point2f to   = cv::Point(srcColorImage.size().width + pt2.x, srcColorImage.size().height + pt2.y);
        cv::line(matchingImage, from, to, randomColor(rng), 2);
    }

    // Display mathing image
    cv::resize(matchingImage, matchingImage, cv::Size(matchingImage.cols/2, matchingImage.rows/2));
}

cv::Mat grabCutter(cv::Mat& image) {
    // define bounding rectangle
    int border = 4;
    int border2 = border + border;
    cv::Rect rectangle(border,border,image.cols-border2,image.rows-border2);
 
    cv::Mat result; // segmentation result (4 possible values)
    cv::Mat bgModel,fgModel; // the models (internally used)
 
    // GrabCut segmentation
    cv::grabCut(image,    // input image
        result,   // segmentation result
        rectangle,// rectangle containing foreground 
        bgModel,fgModel, // models
        1,        // number of iterations
        cv::GC_INIT_WITH_RECT); // use rectangle
    // Get the pixels marked as likely foreground
    cv::compare(result,cv::GC_PR_FGD,result,cv::CMP_EQ);
    // Generate output image
    cv::Mat foreground(image.size(),CV_8UC3,cv::Scalar(0,0,0));
    image.copyTo(foreground,result); // bg pixels not copied
    return foreground;
}

/* 
 * findInliers: 
 *  - Find all the inliers between a source and the pattern detected
 */
void findInliers(vector<cv::KeyPoint> &qKeypoints, vector<cv::KeyPoint> &objKeypoints, 
    vector<cv::DMatch> &matches, const cv::Mat &srcColorImage, const cv::Mat &dstColorImage){
    vector<cv::Point2f> queryCoord;
    vector<cv::Point2f> objectCoord;
    for( unsigned int i = 0; i < matches.size(); i++){
        queryCoord.push_back((qKeypoints[matches[i].queryIdx]).pt);
        objectCoord.push_back((objKeypoints[matches[i].trainIdx]).pt);
    }
    plotMatches(srcColorImage, dstColorImage, queryCoord, objectCoord);
    
    cv::Mat mask;
    vector<cv::Point2f> queryInliers;
    vector<cv::Point2f> sceneInliers;
    cv::Mat H = findFundamentalMat(queryCoord, objectCoord, mask, CV_FM_RANSAC);
    //Mat H = findHomography( queryCoord, objectCoord, CV_RANSAC, 10, mask);
    int inliers_cnt = 0, outliers_cnt = 0;
    for (int j = 0; j < mask.rows; j++){
        if (mask.at<uchar>(j) == 1){
            queryInliers.push_back(queryCoord[j]);
            sceneInliers.push_back(objectCoord[j]);
            inliers_cnt++;
        }else {
            outliers_cnt++;
        }
    }
    plotMatches(srcColorImage, dstColorImage, queryInliers, sceneInliers);
}

//convert uchar to int
inline int dec(uchar x){ 
    if (x>='0'&&x<='9') return (x-'0');
    else if (x>='a'&&x<='f') return (x-'a'+10);
    else if (x>='A'&&x<='F') return (x-'A'+10);
    return 0;
}

// Raw JPEG Binary to OpenCV Matrix
cv::Mat bytea2Mat(const string& f){
    const char* buffer=f.c_str();  
    vector<uchar>::size_type size = strlen((const char*)buffer);
    vector<uchar> jpgbytes(size/2-1); 

    for (size_t i=0; i!=size/2-1;i++) { 
        jpgbytes[i]=(dec(buffer[2*(i+1)])<<4)+dec(buffer[2*(i+1)+1]);
    }
    cout <<size/2<<";"<<jpgbytes.size()<<endl;
    return imdecode(jpgbytes, CV_LOAD_IMAGE_COLOR);
}
/*
* Scene Input/Output OpenCV-Based Processing <======= END
*/

/*
* Input/Output Text-Based Transformation =======> START
*/

static const std::string base64Chars =
"ABCDEFGHIJKLMNOPQRSTUVWXYZ"
"abcdefghijklmnopqrstuvwxyz"
"0123456789+/";

static inline bool isBase64(unsigned char c) {
    return (isalnum(c) || (c == '+') || (c == '/'));
}

// Base64 String decode
// Can be used in JSON Payload decode if the scene was base64 encoded
std::string base64Decode(std::string const& encodedString) {
    int in_len = encodedString.size();
    int i = 0;
    int j = 0;
    int in_ = 0;
    unsigned char char_array_4[4], char_array_3[3];
    std::string ret;

    while (in_len-- && (encodedString[in_] != '=') && isBase64(encodedString[in_])) {
        char_array_4[i++] = encodedString[in_]; in_++;
        if (i == 4) {
            for (i = 0; i < 4; i++)
                char_array_4[i] = base64Chars.find(char_array_4[i]);

            char_array_3[0] = (char_array_4[0] << 2) + ((char_array_4[1] & 0x30) >> 4);
            char_array_3[1] = ((char_array_4[1] & 0xf) << 4) + ((char_array_4[2] & 0x3c) >> 2);
            char_array_3[2] = ((char_array_4[2] & 0x3) << 6) + char_array_4[3];

            for (i = 0; (i < 3); i++)
                ret += char_array_3[i];
            i = 0;
        }
    }

    if (i) {
        for (j = i; j < 4; j++)
            char_array_4[j] = 0;

        for (j = 0; j < 4; j++)
            char_array_4[j] = base64Chars.find(char_array_4[j]);

        char_array_3[0] = (char_array_4[0] << 2) + ((char_array_4[1] & 0x30) >> 4);
        char_array_3[1] = ((char_array_4[1] & 0xf) << 4) + ((char_array_4[2] & 0x3c) >> 2);
        char_array_3[2] = ((char_array_4[2] & 0x3) << 6) + char_array_4[3];

        for (j = 0; (j < i - 1); j++) ret += char_array_3[j];
    }

    return ret;
}

/* 
 * mediaExt: 
 *  - Match the MIME Type of the attachament sent in the request body
 *  - Match the the file extension in the mime type has been defined as application/octect-stream (possible with Amazon S3 bukects/objects)
 */
std::string mediaExt(std::string data){
    if(data.find("image/jpeg") != std::string::npos){
        return ".jpg";
    }else if(data.find("image/png") != std::string::npos){
        return ".png";
    }else if(data.find("image/gif") != std::string::npos){
        return ".gif";
    }else if(data.find("image/jpg") != std::string::npos){
        return ".jpg";
    }else if(data.find(".jpeg") != std::string::npos){
        return ".jpg";
    }else if(data.find(".png") != std::string::npos){
        return ".png";
    }else if(data.find(".jpg") != std::string::npos){
        return ".jpg";
    } else {
        return "";
    }
}

/* 
 * jsonParser: 
 *  - Parse the detection infromation sent by the TCP Server
 *  - Format the response into a Blippar Connect parsable answer
 */
std::string jsonParser(const find_object::DetectionInfo & info, bool debugDetails, Json::Value debugInfo) {
  Json::Value root;
  root["Status"] = 200; 
  if(info.objDetected_.size())
  {
    Json::Value detections;
    Json::Value details;
    QMultiMap<int, int>::const_iterator iterInliers = info.objDetectedInliersCount_.constBegin();
    QMultiMap<int, int>::const_iterator iterOutliers = info.objDetectedOutliersCount_.constBegin();
    QMultiMap<int, QSize>::const_iterator iterSizes = info.objDetectedSizes_.constBegin();
    QMultiMap<int, QString>::const_iterator iterFilePaths = info.objDetectedFilePaths_.constBegin();
    for(QMultiMap<int, QTransform>::const_iterator iter = info.objDetected_.constBegin(); iter!= info.objDetected_.end();)
    {
      char index = 'a';
      int id = iter.key();
      while(iter != info.objDetected_.constEnd() && id == iter.key())
      {

        QString name = QString("object_%1%2").arg(id).arg(info.objDetected_.count(id)>1?QString(index++):"");
        Json::Value connect;
        connect["MarkerId"] = "98825";
        connect["Score"]  = iterInliers.value();
        connect["Keywords"] = name.toStdString();
        detections.append(connect);

        root["Results"].append(connect);

        if(debugDetails) {
            Json::Value homography;
            homography.append(iter.value().m11());
            homography.append(iter.value().m12());
            homography.append(iter.value().m13());
            homography.append(iter.value().m21());
            homography.append(iter.value().m22());
            homography.append(iter.value().m23());
            homography.append(iter.value().m31());  // dx
            homography.append(iter.value().m32());  // dy
            homography.append(iter.value().m33());

            float objectWidth = iterSizes.value().width();
            float objectHeight = iterSizes.value().height();

            // Find corners Qt
            QTransform qtHomography = iter.value();
            QPointF qtTopLeft = qtHomography.map(QPointF(0,0));
            QPointF qtTopRight = qtHomography.map(QPointF(objectWidth,0));
            QPointF qtBottomLeft = qtHomography.map(QPointF(0,objectHeight));
            QPointF qtBottomRight = qtHomography.map(QPointF(objectWidth,objectHeight));

            root["Details"][name.toStdString()]["boundingBox"]["qtTopLeft"].append(qtTopLeft.x());
            root["Details"][name.toStdString()]["boundingBox"]["qtTopLeft"].append(qtTopLeft.y());

            root["Details"][name.toStdString()]["boundingBox"]["qtTopRight"].append(qtTopRight.x());
            root["Details"][name.toStdString()]["boundingBox"]["qtTopRight"].append(qtTopRight.y());

            root["Details"][name.toStdString()]["boundingBox"]["qtBottomLeft"].append(qtBottomLeft.x());
            root["Details"][name.toStdString()]["boundingBox"]["qtBottomLeft"].append(qtBottomLeft.y());

            root["Details"][name.toStdString()]["boundingBox"]["qtBottomRight"].append(qtBottomRight.x());
            root["Details"][name.toStdString()]["boundingBox"]["qtBottomRight"].append(qtBottomRight.y());

            root["Details"][name.toStdString()]["dimensions"]["width"] = iterSizes.value().width();
            root["Details"][name.toStdString()]["dimensions"]["height"] = iterSizes.value().height();
            root["Details"][name.toStdString()]["homography"] = homography;
            root["Details"][name.toStdString()]["detection"]["inliers"] = iterInliers.value();
            root["Details"][name.toStdString()]["detection"]["outliers"] = iterOutliers.value();
            root["Details"][name.toStdString()]["source"]["filepath"] = iterFilePaths.value().toStdString();
            QString filename;

            if(!iterFilePaths.value().isEmpty())
            {
              QFileInfo file(iterFilePaths.value());
              filename=file.fileName();
            }
            root["Details"][name.toStdString()]["source"]["filename"] = filename.toStdString();
        }
        ++iter;
        ++iterInliers;
        ++iterOutliers;
        ++iterSizes;
        ++iterFilePaths;
      }
    }
  } else {
    root["Results"] = "[]";
  }

    if(debugDetails) {
        root["Debug"] = debugInfo;
    }

  // write in a nice readible way
  Json::FastWriter fastWriter;
  return fastWriter.write(root).c_str();
}

/*
* Input/Output Text-Based Transformation =======> END
*/

/*
*
* Part of the Tufao Server service
* Notes: 
*  - As the findObject framework rely, for the moment, on QT4.8, we do have loads of restrcition on objects sharing
*  - We will refactor the code to use more Boost templates
*
* Main goals: 
*  - Simple/efficient service scalable through docker
*  - Define the recognition parameters with POSt or GET arguments
*  - Manage virtual namespaces for some visual dictionnaries (logos, Maxfactor)
*
* PostHandler =======> START
*/

/*
 * Append the data received from the incomging request:
 * - When the End event is triggered the buffer is passed to the onEnd method 
 */
PostHandler::PostHandler(HttpServerRequest *request,
                         HttpServerResponse *response, QObject *parent) :
    QObject(parent),
    request(request),
    response(response)
{
    connect(request, SIGNAL(data(QByteArray)), this, SLOT(onData(QByteArray)));
    connect(request, SIGNAL(end()), this, SLOT(onEnd()));
}

/*
 * Append the data received from the incomging request:
 * - When the End event is triggered the buffer is passed to the onEnd method 
 */
void PostHandler::onData(const QByteArray &chunk)
{
    buffer += chunk;
}

void PostHandler::onError(const std::ostringstream & error, Json::Value & logs)
{
    Json::FastWriter fastWriter;
    logs["Error"].append(error.str());
    response->writeHead(Tufao::HttpServerResponse::BAD_REQUEST);
    response->headers().insert("Content-Type", "application/json");
    response->end(fastWriter.write(logs).c_str());  
}

/*
*
* The full request body has been received as a buffer by the web service
*
* Request Processing Steps:
* 1- Instanciate the timer
* 2- Parse the reqequest body
* 3- Extract a JPEG or PNG binary part
* 4- Check the MIME Type
* 5- Import the binary buffer into OPENCV
* 6- Check the channels and the depth
* 7- Check the data in the matrix (not empty)
* 8- Check the size of the matric (width/height)
* 9- Crop 70% of the center of the picture
* 10- Save the cropped scene for local verification (need to forward to a Websocket and S3 bucket)
* 11- Find squares (all squares and the main one) in the cropped scene
* 12- Save the pre-processed scene for squares or shapes for local verification (need to forward to a Websocket and S3 bucket)
* 13- Connect to the TCP Server 
* 14- Encode the final output into a PNG buffer to send to the TCP Server
* 15- Wait for the waitForReadyRead event with a timeout of (1000ms => too much for the moment) 
* 16- Wait for the dataReceived event and parse the object received (We should had the boundary hash as a signature to match requests) 
*
* Notes: 
* 1- We will manually parse the request Body to extract the binary file for ease now
* 2- Only one request per port
* 3- Need to clone or spawn new findObject objects in the TCP server if the requests rate grows
* 4- Need to manage some asynchronous processing like OpenVOC, Crossloading to Amazon S3
*
* Deployment notes: 
* 1- Use Docker+Crane to manage replicas on a single EC2 instance
* 2- Use Kubernetes for cluster deployement
*    a- Need to get a service discovery system (Think to use ETCD2CPP to get backend/frontends mapping stored=Hot reloads) 
*    b- Need to JSON RPC other recognition systems 
*    b- Need to forward logs with filebeats to ElasticSearch, Kibana4 and Logstash
*/
void PostHandler::onEnd()
{

    /*
     * Init the performance timer
     * Start >>> 
     */

        // Note: Need to see if can it make it work with Ealstci filebeat for faster logging gathering into elasticsearch
        QTime time; // Include the Qt Time class
        time.start(); // Start the timer to get the time elapsed between the different processing steps

    /*
     * <<< End
     * Init the performance timer
     */

    /*
     * Init the logging/debugging preferences
     * Start >>> 
     * Note: Need to be activated as GET or POST Parameter through the router object
     */

        bool debugDetails = true;
        bool bufferOutput = false;
        ULogger::setType(ULogger::kTypeConsole);
        ULogger::setLevel(ULogger::kInfo);
        ULogger::setPrintWhere(false);
        ULogger::setPrintTime(false);

    /*
     * <<< End
     * Init the logging preferences
     */ 

    /*
     * Init the JSON Objects appending the different processing results or debugging informations
     * Start >>> 
     */

        Json::FastWriter fastWriter;
        Json::Value connect;
        Json::Value logs;
        logs["Status"] = "0"; // Status code returned (Custom for Blippar Connect)
        Json::Value exifLogs;

    /*
     * <<< End
     * Init the logging preferences
     */ 

    /*
     * Init the variable to store the incoming requests variables and components
     * Start >>> 
     */

        std::string fileData; // Note: we can optimize the string management const string 
        std::string preProcessingFilter = "";
        std::string filterName = "";
        std::string origInput;
        std::string fileName;
        std::string fileNamePrefix;
        std::string err = "";
        std::ostringstream error; // Error messages (Error code detected or abnornal input state after pre-rpocessing or filtering )
        std::ostringstream info; // Information messages (Key Performance Indicators)
        std::ostringstream detect; // Detection messages received by the TCP server or distributed proxy

    /*
     * <<< End
     * Init the variable to store the incoming requests variables and components
     */

    /*
     * Init the variables for disptaching the current visual scene for visual mining
     * Start >>> 
     */

        QString ipAddress; // IP Address for the main TCP server endpoint (Could be Distributed search IP later)
//        quint16 portOut = 1979;

    /*
     * <<< End
     * Init the variables for disptaching the current visual scene for visual mining
     */

    if(bufferOutput) { // For debugging the buffer received

        /*
         * Output the raw buffer received from the incoming request
         * Start >>> 
         */

        response->writeHead(Tufao::HttpServerResponse::OK);
        response->headers().insert("Content-Type", "application/json");
        response->end(buffer); // Each time we call this function the processing is stopped

        /*
         * <<< End
         * Output the raw buffer received from the incoming request
         */        

    } else {

        // Get the boundary code: we will use it as a unique key to distribute answers or identify requests
        // Will help to identify problems with the following:
        // - Falses/positives
        // - Compare to exfi informations
        // - Resolution problems
        // - Channel or Depth problems
        // - Orientation problems

        /*
         * Get the boundary request body hash
         * Start >>> 
         */

        /*
        detect << "OpenCV version is: " << cv::getBuildInformation().c_str();
        logs["Info"].append(detect.str());
        detect.str("");
        */

        detect << "OpenCV version : " << CV_VERSION;
        logs["Info"].append(detect.str());
        detect.str("");

        detect << "Major version : " << CV_MAJOR_VERSION;
        logs["Info"].append(detect.str());
        detect.str("");

        detect << "Minor version : " << CV_MINOR_VERSION;
        logs["Info"].append(detect.str());
        detect.str("");

        detect << "Subminor version : " << CV_SUBMINOR_VERSION;
        logs["Info"].append(detect.str());
        detect.str("");

        detect << "getNumberOfCPUs: " << cv::getNumberOfCPUs();
        logs["Info"].append(detect.str());
        detect.str("");

        detect << "getNumThreads: " << cv::getNumThreads();
        logs["Info"].append(detect.str());
        detect.str("");

        detect << "getThreadNum: " << cv::getThreadNum();
        logs["Info"].append(detect.str());
        detect.str("");

        detect << "getTickFrequency: " << cv::getTickFrequency();
        logs["Info"].append(detect.str());
        detect.str("");

        detect << "getCPUTickCount: " << cv::getCPUTickCount();
        logs["Info"].append(detect.str());
        detect.str("");

        detect << "useOptimized? " << cv::useOptimized();
        logs["Info"].append(detect.str());
        detect.str("");

        std::string input(buffer.constData(), buffer.length());    
        int startBoundary = input.find("--------------------------")+26;
        int endBoundary = input.rfind("\r\nContent-Disposition");
        std::string Boundary = input.substr(startBoundary,endBoundary-startBoundary);
        if(debugDetails) {
            detect << "Matching the Boundary Code ----" << Boundary.c_str() << "----, (" << time.elapsed() << " ms)";
            logs["Info"].append(detect.str());
            detect.str("");
        }

        /*
         * <<< End
         * Get the boundary request body hash
         */

        int isFile = input.find("name=\"file\"");
        if(!isFile) {

        } else {

            int start = input.find("\r\n\r\n") + 4;
            int end = input.rfind("\r\n--");
            if(debugDetails) {
                detect << "Extracting the scene from the form data ending at character #" << start << ", (" << time.elapsed() << " ms)";
                logs["Info"].append(detect.str());
                detect.str("");
                detect << "Extracting the scene from the form data ending at character #" << end << ", (" << time.elapsed() << " ms)";
                logs["Info"].append(detect.str());
                detect.str("");
                detect << "Extracting the scene from the form data, (" << time.elapsed() << " ms)";
                logs["Info"].append(detect.str());
                detect.str("");
            }

            if (start != -1 && end != -1 ){
                fileData = input.substr(start,end-start);
            } else {

                error << " Unable to parse a scene from the request ";
                this->onError(error, logs);

            }

            // Lower then a small value
            if (fileData.size() <= 2048) {

                error << " Unable to parse a scene from the request ";
                this->onError(error, logs);

            } else {

                // We shoudl use const string for such string parsing
                std::string mimeType = mediaExt(input);

                if(mimeType=="")
                {
                    // No mime type, maybe it is a routing error as the current processing expect only POST Requests
                    error << " Unable to detect a valid MIME Type from the current request, (" << time.elapsed() << " ms)";
                    this->onError(error, logs);
                } 
                else 
                {

                    // We got a MIMETYPE potentially from JPG or PNG source
                    if(debugDetails) {
                        detect << "MimeType detected " << mimeType << ", (" << time.elapsed() << " ms)";            
                        logs["Info"].append(detect.str());
                        detect.str("");
                        detect << "Request a detection with the current setup, (" << time.elapsed() << " ms)";
                        logs["Info"].append(detect.str());
                        detect.str("");
                    }

                    // Define the 3 main matrics for this requests

                    cv::Mat scene; // INput matrix to check validity
                    cv::Mat crop; // Always sent as the final matrix
                    cv::Mat filtered; // Depends on the input received (raw Jpeg, JPEG, PNGs): Intermediate matrix
                    cv::Mat copyOrig;
                    // Check the MimeType of the binary input
                    if(mimeType==".jpg" || mimeType==".png") {

                        // Quick notes: we need to think about multipart related processing as for kubeOCR
                        std::vector<uchar> convertedScene(fileData.begin(), fileData.end());
                        try {
                            scene = cv::imdecode(convertedScene, CV_LOAD_IMAGE_COLOR);                    
                            copyOrig = scene;
                        } catch(cv::Exception & e) {
                            error <<  "imdecode exception: " << e.what() << "Maybe the buffer is invalid";
                            scene = cv::Mat();
                            this->onError(error, logs);
                        } catch ( const std::exception& e ) {
                            // standard exceptions
                            error << "imdecode exception: " << e.what() << "Maybe the buffer is invalid";
                            scene = cv::Mat();
                            this->onError(error, logs);
                        }

                    } else {

                        // Stop processing as we have a doubt on the input format as we accept only PNG or JPEGs input
                        error << " MIME Type Incorrect detected [" << mimeType << "], (" << time.elapsed() << " ms)";
                        this->onError(error, logs);

                    }

                    // Check if the channels are valid for further processing (Mask, Equalize Histogram, Background removal)
                    if(scene.channels() >= 3 || scene.depth() != CV_8U)
                    {

                        // Debugging information about channels and depth
                        detect << "Number of channels: " << scene.channels() << ", (" << time.elapsed() << " ms)";            
                        logs["Info"].append(detect.str());
                        detect.str("");

                        detect << "Scene depth: " << scene.depth() << ", (" << time.elapsed() << " ms)";            
                        logs["Info"].append(detect.str());
                        detect.str("");

                        detect << "Number of channels: " << scene.type() << ", (" << time.elapsed() << " ms)";            
                        logs["Info"].append(detect.str());
                        detect.str("");

                        detect << "Number of channels: " <<  mimeType.c_str() << ", (" << time.elapsed() << " ms)";            
                        logs["Info"].append(detect.str());
                        detect.str("");

                        cv::Size ss;
                        try {
                            ss = scene.size();
                        } catch(cv::Exception & e) {
                            error <<  "Get Scene Size exception: " << e.what() << "Maybe the scene is invalid ";
                            scene = cv::Mat();
                            this->onError(error, logs);
                        } catch ( const std::exception& e ) {
                            // standard exceptions
                            error <<  "Get Scene Size exception: " << e.what() << "Maybe the scene is invalid ";
                            scene = cv::Mat();
                            this->onError(error, logs);
                        }

                        detect << "Number of channels: " <<  ss.width << ", (" << time.elapsed() << " ms)";            
                        logs["Info"].append(detect.str());
                        detect.str("");

                        detect << "Scene Original height: " <<  ss.height << ", (" << time.elapsed() << " ms)";            
                        logs["Info"].append(detect.str());
                        detect.str("");

                        // Quick note create a void method to append detect/log/error messages
                        detect << "Scene need to be converted to color, (" << time.elapsed() << " ms)";
                        logs["Info"].append(detect.str());
                        detect.str("");

                        fileNamePrefix = "./tests/"+Boundary+"_";

                        /*
                        try {
                            equalizeIntensity(scene, fileNamePrefix);
                        } catch (exception& e) {
                            UERROR("Error while equalizeIntensity the scene; %s", e.what());
                        }
                        */

                        try {
                            sceneHeatmap(scene, fileNamePrefix);
                        } catch (exception& e) {
                            UERROR("Error while sceneHeatmap the scene; %s", e.what());
                        }

                        // Quick note: maybe we should implement a swicth bewteen 
                        try {
                            cv::Mat grabcut;
                            grabcut = grabCutter(scene);
                            autocrop(grabcut, filtered);
                            try {
                                fileName = "./tests/"+Boundary+"_foreground.jpg";
                                imwrite( fileName, grabcut);
                                UINFO("Extracted a foreground extract");
                            } catch (exception& e) {
                                UERROR("Error while writing a copy of foreground scene; %s", e.what());
                            }
                        } catch(cv::Exception & e) {
                            error << "cvtColor exception: %s. Maybe the channels, depth or input format is invalid " << e.what() << "], (" << time.elapsed() << " ms)";
                            filtered = cv::Mat();
                            scene = cv::Mat();
                            this->onError(error, logs);
                        } catch ( const std::exception& e ) {
                            // standard exceptions
                            error << "cvtColor exception: %s. Maybe the channels, depth or input format is invalid " << e.what() << "], (" << time.elapsed() << " ms)";
                            filtered = cv::Mat();
                            scene = cv::Mat();
                            this->onError(error, logs);
                        }
                    } else {
                        // Scene was already a valid input
                        detect << "Scene already having one channel and format CV_8U, (" << time.elapsed() << " ms)";
                        logs["Info"].append(detect.str());
                        detect.str("");
                        /*
                        try {
                        } catch(cv::Exception & e) {
                            UERROR("Error while autocroping a scene already having one channel and format CV_8U; %s", e.what());
                        } catch ( const std::exception& e ) {
                            UERROR("Error while autocroping a scene already having one channel and format CV_8U; %s", e.what());
                        }*/
                        cv::cvtColor(scene, filtered, cv::COLOR_BGR2GRAY);
                    }                        

                    // Check if the matrix is not empty of data
                    if(!filtered.data) {

                        error << " Unable to decode the picture received, (" << time.elapsed() << " ms)";
                        this->onError(error, logs);

                    }

                    // Count the number of columns in the matrix (Some controls can be merged into a more efficient one)
                    // Quick Notes: LibRaw can be a good solution to convert all the raw bytes up-front
                    cv::Size s;
                    if (filtered.cols == 0) {

                        error << " conversion problem of the matrix, (" << time.elapsed() << " ms)";
                        this->onError(error, logs);

                    } else {

                        try {
                            // Get the size parameters of the filtered scene
                            s = filtered.size();
                        } catch (cv::Exception& e) {
                            cout << "Exception occurred " << e.msg << endl;
                        }

                    }

                    if(mimeType==".jpeg"){

                        // Extract any kind of context from the EXIF Header
                        // Notes:
                        // - Supports common Exif fields including GPS, ISO speed, etc.
                        // - No uses of new/malloc.
                        // Based on the description of the EXIF file format at:
                        // - http://park2.wakwak.com/~tsuruzoh/Computer/Digicams/exif-e.html
                        // - http://www.media.mit.edu/pia/Research/deepview/exif.html
                        // - http://www.exif.org/Exif2-2.PDF

                        easyexif::EXIFInfo exif; 

                        int code = exif.parseFrom((const unsigned char *)fileData.data(), fileData.length());
                        if (code) {

                            // Append the error to the detection logs
                            detect << "Error parsing EXIF: code " << code << ", (" << time.elapsed() << " ms)";            
                            logs["Info"].append(detect.str());
                            detect.str("");
                            // We do not stop the process if the EXIF as not been extracted as it is optional
                            // Not always garanteed by the Blippar Application

                        } else {

                            // Append all 
                            exifLogs["Camera make"].append(exif.Make.c_str());
                            exifLogs["Camera model"].append(exif.Model.c_str());
                            exifLogs["Software"].append(exif.Software.c_str());
                            exifLogs["Bits per sample"].append(exif.BitsPerSample);
                            exifLogs["Image width"].append(exif.ImageWidth);
                            exifLogs["Image height"].append(exif.ImageHeight);
                            exifLogs["Image description"].append(exif.ImageDescription.c_str());
                            exifLogs["Image orientation"].append(exif.Orientation);
                            exifLogs["Image copyright"].append(exif.Copyright.c_str());
                            exifLogs["Image date/time"].append(exif.DateTime.c_str());
                            exifLogs["Original date/time"].append(exif.DateTimeOriginal.c_str());
                            exifLogs["Digitize date/time"].append(exif.DateTimeDigitized.c_str());
                            exifLogs["Subsecond time"].append(exif.SubSecTimeOriginal.c_str());
                            exifLogs["F-stop"].append(exif.FNumber);
                            exifLogs["ISO speed"].append(exif.ISOSpeedRatings);
                            exifLogs["Subject distance"].append(exif.SubjectDistance);
                            exifLogs["Exposure bias"].append(exif.ExposureBiasValue);
                            exifLogs["Flash used?"].append(exif.Flash);
                            exifLogs["Metering mode"].append(exif.MeteringMode);
                            exifLogs["Lens focal length"].append(exif.FocalLength);
                            exifLogs["35mm focal length"].append(exif.FocalLengthIn35mm);
                            exifLogs["GPS Latitude"].append(exif.GeoLocation.Latitude);
                            exifLogs["GPS Longitude"].append(exif.GeoLocation.Longitude);
                            exifLogs["GPS Altitude"].append(exif.GeoLocation.Altitude);
                            logs["Info"].append(exifLogs);

                        } // if no errors while extracting Exif Informations

                    } // if JPEG MIMETYPE

                    // Check if the initial scene has an acceptable dimension for cropping (70% will be kept)
                    if(s.height < 75 && s.width < 75) // define in the settings
                    {

                        error << "Dimension not appropriate for the scene [Width:" << s.width << "|Height:" << s.height << "] - (" << time.elapsed() << " ms)";
                        this->onError(error, logs);

                    } 
                    else 
                    {

                        /* Start === Region of Interest Cropping */                        

                        // Create a void function for the ROI cropping process
                        // We have another function for polygons
                        /*
                        int ratioWidth     = 95; // our ROI will be 70% of our input image
                        int ratioHeight    = 75; // our ROI will be 70% of our input image

                        // Calaculate width and height of the region of interest
                        int roiWidth  = (int)(s.width*ratioWidth/100);
                        int roiHeight = (int)(s.height*ratioHeight/100);

                        // offsets from image borders
                        int dw = (int)(s.width-roiWidth)/2;
                        int dh = (int)(s.height-roiHeight)/2;

                        // Define the Rectangle for the Region of interest
                        cv::Rect roi;
                        roi.x = dw;
                        roi.y = dh;
                        roi.width = roiWidth;
                        roi.height = roiHeight;

                        // Copy to a local file the temp cropped scene for inspection
                        cv::Mat exportCrop;

                        // Apply the region of interest on the input scene
                        try {

                            crop = filtered(roi); 

                        } catch(cv::Exception & e) {

                            error << "Region of Interest exception, " << e.what() << "  Maybe the cropped scene is invalid (" << time.elapsed() << " ms)";
                            roi = cv::Rect();
                            crop = cv::Mat();
                            filtered  = cv::Mat();
                            this->onError(error, logs);

                        } catch ( const std::exception& e ) {

                            error << "Region of Interest exception, " << e.what() << "  Maybe the cropped scene is invalid (" << time.elapsed() << " ms)";
                            roi = cv::Rect();
                            crop = cv::Mat();
                            filtered  = cv::Mat();
                            this->onError(error, logs);

                        }

                        // Copy the cropped result
                        try {

                            cv::Mat(crop).copyTo(exportCrop);

                        } catch(cv::Exception & e) {

                            error << "copyTo exception,  Maybe the cropped scene is invalid (" << time.elapsed() << " ms)";
                            crop = cv::Mat();
                            exportCrop = cv::Mat();
                            this->onError(error, logs);

                        } catch ( const std::exception& e ) {

                            error << "copyTo exception,  Maybe the cropped scene is invalid (" << time.elapsed() << " ms)";
                            exportCrop = cv::Mat();
                            this->onError(error, logs);

                        }
                        */

                        /*
                        try {
                            fileName = "./tests/"+Boundary+"_exportCrop.jpg";
                            imwrite( fileName, exportCrop );
                        } catch(cv::Exception & e) {
                            UERROR("Write Image  exception in exportSquares, maybe the _exportCrop matrix is corrupted/empty; %s", e.what());
                        } catch ( const std::exception& e ) {
                            // standard exceptions
                            UERROR("Write Image  exception in exportSquares, maybe the _exportCrop matrix is corrupted/empty; %s", e.what());
                        }
                        */

                        /* End === Region of Interest Cropping */

                        // Append some debugging messages (Useful for local Postman tests or ELK analytics)
                        if(debugDetails) {

                            // Dimension of the initial scene
                            cv::Size c = crop.size();
                            detect << "Dimension accepeted for the scene [Width:" << s.width << "|Height:" << s.height << "] - (" << time.elapsed() << " ms)";
                            logs["Info"].append(detect.str());
                            detect.str("");

                            // Dimension of the cropped scene
                            detect << "Dimension accepeted for the Region of interest [Width:" << c.width << "|Height:" << c.height << "] - (" << time.elapsed() << " ms)";
                            logs["Info"].append(detect.str());
                            detect.str("");

                            // 
                            detect << "The scene was extracted form the form and the encoded successfully, (" << time.elapsed() << " ms)";
                            logs["Info"].append(detect.str());
                            detect.str("");

                            /*
                            // Find Squares
                            fileNamePrefix = "./tests/"+Boundary+"_";
                            std::vector<std::vector<cv::Point> > squares;
                            std::vector<cv::Point> biggest_square;
                            cv::Mat exportSquares;

                            try {
                                sceneHeatmap(filtered, fileNamePrefix);
                            } catch (exception& e) {
                                UERROR("Error while sceneHeatmap the scene; %s", e.what());
                            }

                            try {
                                equalizeIntensity(filtered, fileNamePrefix);
                            } catch (exception& e) {
                                UERROR("Error while equalizeIntensity the scene; %s", e.what());
                            }

                            try {
//                                findSquares(crop, squares, fileNamePrefix);
                                findSquares2(filtered, squares);
                            } catch (exception& e) {
                                UERROR("Error while looking for squares in the cropped scene; %s", e.what());
                            } 

                            try {
                                findLargestSquare(squares, biggest_square);
                            } catch (exception& e) {
                                UERROR("Error while looking for the largest square in the cropped scene; %s", e.what());
                            }

                            try {
                                exportSquares = debugSquares(squares, exportSquares);
                            } catch (exception& e) {
                                UERROR("Error while looking for the largest square in the cropped scene; %s", e.what());
                            }

                            try {
                                fileName = "./tests/"+Boundary+"_test-exportSquares.jpg";
                                imwrite( fileName, exportSquares );
                            } catch(cv::Exception & e) {
                                UERROR("Write Image  exception in exportSquares, maybe the exportSquares matrix is corrupted; %s", e.what());
                            } catch ( const std::exception& e ) {
                                // standard exceptions
                                UERROR("Write Image  exception in exportSquares, maybe the exportSquares matrix is corrupted; %s", e.what());
                            }*/
                            /*
                            try {
                                fileName = "./tests/"+Boundary+"_autocrop.jpg";
                                imwrite( fileName, crop);
                            } catch (exception& e) {
                                UERROR("Error while writing a copy of auto-cropped scene; %s", e.what());
                            }

                            try {
                                fileName = "./tests/"+Boundary+"_original.jpg";
                                imwrite( fileName, copyOrig );
                            } catch (exception& e) {
                                UERROR("Error while writing a copy of original scene; %s", e.what());
                            }
                            */
                        }

                    }

                    cv::Mat grayscaleImg;
                    if(filtered.channels() != 1 || filtered.depth() != CV_8U)
                    {
                        cv::cvtColor(filtered, grayscaleImg, cv::COLOR_BGR2GRAY);
                    } else {
                        grayscaleImg = filtered;
                    }

                    try {
                        fileName = "./tests/"+Boundary+"_before_emit.jpg";
                        imwrite(fileName, grayscaleImg); 
                    } catch (exception& e) {
                        UERROR("Error while writing a copy of beforeEmit scene; %s", e.what());
                    }

                    response->writeHead(Tufao::HttpServerResponse::OK);
                    response->headers().insert("Content-Type", "application/json");
                    response->end("{\"status\":\"200\",\"msg\":\"cropped\"}");

                    /*
                    TcpResponse detection;
                    ipAddress = QHostAddress(QHostAddress::LocalHost).toString();
                    detection.connectToHost(ipAddress, portOut);

                    // Check if can establish a communication with the TCP Server inside a fixed timeout
                    if(!detection.waitForConnected(3000))
                    {

                        error << " Unable to connect to TCP SERVER at " << ipAddress.toStdString().c_str() << " = " << portOut << ", (" << time.elapsed() << " ms)";
                        this->onError(error, logs);

                    } else {

                        if(debugDetails) {
                            detect << "Connected to the Visual Dictionary at " << ipAddress.toStdString().c_str() << " = " << portOut << ", (" << time.elapsed() << " ms)";          
                            logs["Info"].append(detect.str());
                            detect.str("");
                        }

                        // either filtered
                        QByteArray block;
                        QDataStream out(&block, QIODevice::WriteOnly);
                        out.setVersion(QDataStream::Qt_4_0);
                        out << (quint64)0;

                        std::vector<uchar> buffy;

                        try {
                            cv::imencode(".jpeg", crop, buffy);
                        } catch(cv::Exception & e) {
                            error << "imencode exception, maybe the filtered scene is corrupted (" << time.elapsed() << " ms)";
                            crop = cv::Mat();
                            this->onError(error, logs);
                        } catch ( const std::exception& e ) {
                            error << "imencode exception, maybe the filtered scene is corrupted (" << time.elapsed() << " ms)";
                            crop = cv::Mat();
                            this->onError(error, logs);
                        }

                        out << (quint32)2;
                        // out << "us";
                        // out << "cache";
                        quint64 imageSize = buffy.size();
                        out << imageSize;
                        out.writeRawData((char*)buffy.data(), (int)buffy.size());

                        out.device()->seek(0);
                        out << (quint64)(block.size() - sizeof(quint64));
                        qint64 bytes = detection.write(block);

                        if(debugDetails) {
                            detect << "[CLIENT] Service published (" << (int)bytes << " bytes)! (" << time.elapsed() << " ms)";
                            logs["Info"].append(detect.str());
                            detect.str("");
                        }

                        if(detection.waitForBytesWritten()) 
                        {
                            if(detection.dataReceived())
                            {
                                if(debugDetails) {                            
                                    detect << "Response received!, (" << time.elapsed() << " ms)";
                                    logs["Info"].append(detect.str());
                                    detect.str("");
                                }

                                // print detected objects
                                if((detection.info().objDetected_.size() && debugDetails))
                                {
                                    QList<int> ids = detection.info().objDetected_.uniqueKeys();
                                    for(int i=0; i<ids.size(); ++i)
                                    {
                                        int count = detection.info().objDetected_.count(ids[i]);
                                        if(count == 1)
                                        {
                                            if(debugDetails) {
                                                detect << "Object " << ids[i] << " detected... , (" << time.elapsed() << " ms)";
                                                logs["Info"].append(detect.str());
                                                detect.str("");
                                            }
                                        }
                                        else
                                        {
                                            detect << "Object " << ids[i] << " detected " << count << " times... , (" << time.elapsed() << " ms)";
                                            logs["Info"].append(detect.str());
                                            detect.str("");
                                        }
                                    }

                                }
                                else if(debugDetails)
                                {

                                    detect << "No objects detected, (" << time.elapsed() << " ms)";
                                    logs["Info"].append(detect.str());
                                    detect.str("");

                                } // Nothing found

                                logs["Status"] = "200";
                                response->writeHead(Tufao::HttpServerResponse::OK);
                                response->headers().insert("Content-Type", "application/json");
                                detection.close();                                
                                response->end(jsonParser(detection.info(), debugDetails, logs["Info"]).c_str());

                            }

                        } // ready to read received
                        else {
                            error << "No welcome from the TCP Server " << ipAddress.toStdString().c_str() << " = " << portOut << ", (" << time.elapsed() << " ms)";
                            this->onError(error, logs);                            

                        }

                    } // Connect to the TCP Server
                    */
                } // No Vdalid Mime type

            } // Valid size for the picture

        } // Is file detected in the request body ?

    } // buffer output or processing

}

/*
*
* PostHandler =======> END
*
*/
