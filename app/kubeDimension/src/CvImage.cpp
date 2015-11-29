/*

    kubeVision - OpenCV
    Modified by: Luc Michalski - 2015
    New features: Web-service and distributed search
    Based on: Find-Object - Mathieu Labbe - IntRoLab - Universite de Sherbrooke
    URL: https://github.com/introlab/find-object

*/

#include "find_object/CvImage.h"

CVImage::CVImage()
{

}

CVImage::CVImage(IplImage ipl_image)
{
    this->ipl_image = ipl_image;
    this->q_image = *(CVUtil::qimage_from_ipl_image(&this->ipl_image));
	
}

CVImage::CVImage(QImage q_image)
{
    this->q_image = q_image;
    this->ipl_image = *(CVUtil::iplimage_from_qimage(&this->q_image));
	
}

CVImage::CVImage(IplImage ipl_image, QImage q_image)
{
    this->ipl_image = ipl_image;
    this->q_image = q_image;
}

CVImage::~CVImage()
{
    //no heap-allocated objects
}
