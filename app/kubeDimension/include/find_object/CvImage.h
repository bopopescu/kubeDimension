/*

    kubeVision - OpenCV
    Modified by: Luc Michalski - 2015
    New features: Web-service and distributed search
    Based on: Find-Object - Mathieu Labbe - IntRoLab - Universite de Sherbrooke
    URL: https://github.com/introlab/find-object

*/

#ifndef CV_IMAGE_H
#define CV_IMAGE_H

#include <QtGui/QImage>

#include "CvUtil.h" 
/*!
A simple class to encapsulate IplImage-QImage pairs.
*/
class CVImage
{
public:
        CVImage();
        CVImage(QImage q_image);
        virtual ~CVImage();

        /*member variables*/
        QImage q_image;
};

#endif
