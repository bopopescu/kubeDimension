/*

    kubeVision - OpenCV (part of the KubeVision)
    Modified by: Luc Michalski - 2015
    New features: Web-service and distributed search
    Based on: Find-Object - Mathieu Labbe - IntRoLab - Universite de Sherbrooke
    URL: https://github.com/introlab/find-object

*/
    
#include "find_object/TcpServer.h"
//#include "find_object/Thread.h"
#include "find_object/Worker.h"

#include <QtCore/QThread>

using namespace Tufao;

TcpServer::TcpServer(QObject *parent) :
    QTcpServer(parent),
    i(0)
{
}

void TcpServer::run(int threadsNumber, int port,
                    AbstractHttpServerRequestHandlerFactory *handlerFactory)
{
    workers.reserve(threadsNumber);
    for (int i = 0;i != threadsNumber;++i) {
        Worker *worker = new Worker(handlerFactory);
        QThread *workerThread = new QThread(this);

        worker->moveToThread(workerThread);
        workerThread->start();

        workers.push_back(worker);
    }
    listen(QHostAddress::LocalHost, port);
}

void TcpServer::incomingConnection(int handle)
{
    workers[(i++) % workers.size()]->addConnection(handle);
}