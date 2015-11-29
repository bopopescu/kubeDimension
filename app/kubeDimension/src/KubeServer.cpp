/*

    kubeVision - OpenCV (part of the KubeVision)
    Modified by: Luc Michalski - 2015
    New features: Web-service and distributed search
    Based on: Find-Object - Mathieu Labbe - IntRoLab - Universite de Sherbrooke
    URL: https://github.com/introlab/find-object

*/
    
#include "KubeServer.h"
#include "KubeThread.h"

KubeServer::KubeServer(QObject *parent) :
    QTcpServer(parent),
    i(0)
{
}

KubeServer::~KubeServer()
{
    // the thread can't have a parent then...
    foreach (KubeThread* t, kthreads) {
        t->quit();
    }
    foreach (KubeThread* t, kthreads) {
        t->wait();
        delete t;
    }
}

void KubeServer::run(int threadsNumber, QHostAddress host, int port,
                    Tufao::AbstractHttpServerRequestHandlerFactory *handlerFactory)
{
    kthreads.reserve(threadsNumber);
    for (int i = 0;i != threadsNumber;++i) {
        kthreads.push_back(new Thread(handlerFactory->createHandler(this),
                                     this));
        kthreads[i]->start();
    }
    listen(host, port);
}

void KubeServer::incomingConnection(int handle)
{
    kthreads[(i++) % kthreads.size()]->addConnection(handle);
}

