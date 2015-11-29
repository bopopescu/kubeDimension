/*

    kubeVision - OpenCV (part of the KubeVision)
    Modified by: Luc Michalski - 2015
    New features: Web-service and distributed search
    Based on: Find-Object - Mathieu Labbe - IntRoLab - Universite de Sherbrooke
    URL: https://github.com/introlab/find-object

*/
    
#include "find_object/Thread.h"
#include <QtNetwork/QTcpSocket>
#include <Tufao/HttpServerRequest>
#include <Tufao/Headers>

using namespace Tufao;

Thread::Thread(Tufao::AbstractHttpServerRequestHandler *handler,
               QObject *parent) :
    QThread(),
    handler(handler)
{
    // need this to make the signals and slots run in current thread
    moveToThread(this);
    connect(parent, SIGNAL(destroyed()), this, SLOT(quit()));
    connect(parent, SIGNAL(destroyed()), this, SLOT(deleteLater()));
    connect(this, SIGNAL(newConnection(int)), this, SLOT(onNewConnection(int)));
}

void Thread::addConnection(int socketDescriptor)
{
    Q_EMIT newConnection(socketDescriptor);
}

void Thread::onNewConnection(int socketDescriptor)
{
    QTcpSocket *socket = new QTcpSocket(this);
    if (!socket->setSocketDescriptor(socketDescriptor)) {
        delete socket;
        return;
    }

    HttpServerRequest *handle = new HttpServerRequest(socket, this);

    connect(handle, SIGNAL(ready()), this, SLOT(onRequestReady()));
    connect(handle, SIGNAL(upgrade(QByteArray)),
            this, SLOT(onUpgrade(QByteArray)));
    connect(socket, SIGNAL(disconnected()), handle, SLOT(deleteLater()));
    connect(socket, SIGNAL(disconnected()), socket, SLOT(deleteLater()));
}

void Thread::onRequestReady()
{
    HttpServerRequest *request = qobject_cast<HttpServerRequest *>(sender());

    QAbstractSocket *socket = request->socket();
    HttpServerResponse *response
            = new HttpServerResponse(socket, request->responseOptions(), this);

    connect(socket, SIGNAL(disconnected()), response, SLOT(deleteLater()));
    connect(response, SIGNAL(finished()), response, SLOT(deleteLater()));

    if (request->headers().contains("Expect", "100-continue"))
        response->writeContinue();

    handler->handleRequest(request, response);
}

void Thread::onUpgrade(const QByteArray &)
{
    HttpServerRequest *request = qobject_cast<HttpServerRequest *>(sender());
    delete request;
}