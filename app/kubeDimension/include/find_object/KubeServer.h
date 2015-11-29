/*

	kubeVision - OpenCV (part of the KubeVision)
	Modified by: Luc Michalski - 2015
	New features: Web-service and distributed search
	Based on: Find-Object - Mathieu Labbe - IntRoLab - Universite de Sherbrooke
	URL: https://github.com/introlab/find-object

*/
	
#ifndef KUBESERVER_H
#define KUBESERVER_H

#include <QtNetwork/QTcpServer>
#include <QtCore/QList>

#include <Tufao/AbstractHttpServerRequestHandlerFactory>

class KubeThread;

class KubeServer : public QObject
{
    Q_OBJECT
public:
    explicit KubeServer(QObject *parent = 0);
    virtual ~KubeServer();

    void run(int threadsNumber, QHostAddress host, int port,
             Tufao::AbstractHttpServerRequestHandlerFactory *handlerFactory);

Q_SIGNALS:
    void newConnection(int socketDescriptor);

protected:
    void incomingConnection(int handle);

private:
    QList<KubeThread*> kthreads;
    int i;
};

#endif // KUBESERVER_H