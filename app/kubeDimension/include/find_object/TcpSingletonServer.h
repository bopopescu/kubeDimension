/*

	kubeVision - OpenCV
	Modified by: Luc Michalski - 2015
	New features: Web-service and distributed search
	Based on: Find-Object - Mathieu Labbe - IntRoLab - Universite de Sherbrooke
	URL: https://github.com/introlab/find-object

*/

#ifndef TCPSERVER_H_
#define TCPSERVER_H_

#include "find_object/FindObjectExp.h" // DLL export/import defines

#include "find_object/DetectionInfo.h"
#include <opencv2/opencv.hpp>

#include <QtNetwork/QTcpServer>

namespace find_object {

class QNetworkSession;

class FINDOBJECT_EXP TcpServer : public QTcpServer
{
	Q_OBJECT

public:
	enum Service {
		kAddObject,   // id fileName imageSize image
		kRemoveObject, // id
		kDetectObject // context imageSize image
	};

public:
	TcpServer(quint16 port = 0, QObject * parent = 0);

	QHostAddress getHostAddress() const;
	quint16 getPort() const;

public Q_SLOTS:
	void publishDetectionInfo(const find_object::DetectionInfo & info);

private Q_SLOTS:
	void addClient();
	void readReceivedData();
	void displayError(QAbstractSocket::SocketError socketError);
	void connectionLost();

Q_SIGNALS:
	void addObject(const cv::Mat &, int, const QString &);
	void removeObject(int);
	void detectObject(const cv::Mat &);

private:
	QMap<int, quint64> blockSizes_;
};

} // namespace find_object

#endif /* TCPSERVER_H_ */
