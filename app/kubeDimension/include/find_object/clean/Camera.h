/*

	kubeVision - OpenCV
	Modified by: Luc Michalski - 2015
	New features: Web-service and distributed search
	Based on: Find-Object - Mathieu Labbe - IntRoLab - Universite de Sherbrooke
	URL: https://github.com/introlab/find-object

*/

#ifndef CAMERA_H_
#define CAMERA_H_

#include "find_object/FindObjectExp.h" // DLL export/import defines

#include <opencv2/highgui/highgui.hpp>
#include <QtCore/QObject>
#include <QtCore/QTimer>
#include <QtGui/QImage>

namespace find_object {

class CameraTcpServer;

class FINDOBJECT_EXP Camera : public QObject {
	Q_OBJECT
public:
	Camera(QObject * parent = 0);
	virtual ~Camera();

	virtual bool start();
	virtual void stop();
	virtual bool isRunning() {return cameraTimer_.isActive();}

	void pause();
	int getTotalFrames();
	int getCurrentFrameIndex();
	int getPort();
	void moveToFrame(int frame);

Q_SIGNALS:
	void imageReceived(const cv::Mat & image);
	void finished();

public Q_SLOTS:
	virtual void updateImageRate();
	virtual void takeImage();

protected:
	void startTimer();
	void stopTimer();

private:
	cv::VideoCapture capture_;
	QTimer cameraTimer_;
	QList<std::string> images_;
	unsigned int currentImageIndex_;
	CameraTcpServer * cameraTcpServer_;
};

} // namespace find_object

#endif /* CAMERA_H_ */