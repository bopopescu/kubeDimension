/*

	kubeVision - OpenCV (part of the KubeVision)
	Modified by: Luc Michalski - 2015
	New features: Web-service and distributed search
	Based on: Find-Object - Mathieu Labbe - IntRoLab - Universite de Sherbrooke
	URL: https://github.com/introlab/find-object

*/
	
#ifndef TCPSERVER_H
#define TCPSERVER_H

#include <QTcpServer>
#include <QVector>

#include <Tufao/AbstractHttpServerRequestHandlerFactory>

class Worker;

class TcpServer : public QTcpServer
{
    Q_OBJECT
public:
    explicit TcpServer(QObject *parent = 0);

    void run(int threadsNumber, int port,
             Tufao::AbstractHttpServerRequestHandlerFactory *handlerFactory);

Q_SIGNALS:
    void newConnection(int socketDescriptor);

protected:
    void incomingConnection(int handle);

private:
    QVector<Worker*> workers;
    int i;
};

#endif // TCPSERVER_H