/*

    kubeVision - OpenCV
    Modified by: Luc Michalski - 2015
    New features: Web-service and distributed search
    Based on: Find-Object - Mathieu Labbe - IntRoLab - Universite de Sherbrooke
    URL: https://github.com/introlab/find-object

*/

#ifndef IMAGEPROCESSINGTHREAD_H
#define IMAGEPROCESSINGTHREAD_H
#include "CvImage.h"
#include "CvImageProcessor.h"
#include <QThread>
#include <QMutex>
#include <QDebug>

class ImageProcessingThread : public QThread
{
    Q_OBJECT
public:
    explicit ImageProcessingThread(CVImage *shared_cv_image, QMutex *mutex, QObject *parent = 0);
    virtual ~ImageProcessingThread();
    void run();
    CVImageProcessor* get_image_processor();

Q_SIGNALS:
   void image_processor_instantiated();

private:
    CVImage *shared_cv_image;
    CVImageProcessor *image_processor;
    QMutex *mutex;
};

#endif // IMAGEPROCESSINGTHREAD_H
