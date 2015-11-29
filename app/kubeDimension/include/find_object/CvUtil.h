/*

    kubeVision - OpenCV
    Modified by: Luc Michalski - 2015
    New features: Web-service and distributed search
    Based on: Find-Object - Mathieu Labbe - IntRoLab - Universite de Sherbrooke
    URL: https://github.com/introlab/find-object

*/

#ifndef CVUTIL_H
#define CVUTIL_H

#include <QtGui/QImage>
#include <QTextStream>
#include <QtCore/QFile>


/*
Class contains utility functions for converting IplImage objects to QImage objects and vice-versa.
(plus a simple function to convert a binary resource to a local file -- used, in this program, to write haar cacade XML
files bundled up as binaries back into local XML files, so that they can be passed into OpenCV library functions that 
only take file paths as params.)
*/
class CVUtil
{
public:
    static bool resource_to_file(QString resource_name, QString target_file_name);
};

#endif // CVUTIL_H
