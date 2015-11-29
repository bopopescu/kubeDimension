/*

    kubeVision - OpenCV
    Modified by: Luc Michalski - 2015
    New features: Web-service and distributed search
    Based on: Find-Object - Mathieu Labbe - IntRoLab - Universite de Sherbrooke
    URL: https://github.com/introlab/find-object

*/

#ifndef WORKER_H
#define WORKER_H

#include <QtCore/QObject>
#include <Tufao/AbstractHttpServerRequestHandlerFactory>

class Worker : public QObject
{
    Q_OBJECT
public:
    explicit Worker(Tufao::AbstractHttpServerRequestHandlerFactory *factory);

    void addConnection(int socketDescriptor);

Q_SIGNALS:
    void newConnection(int socketDescriptor);

private Q_SLOTS:
    void onNewConnection(int socketDescriptor);
    void onRequestReady();
    void onUpgrade(const QByteArray &);

private:
    Tufao::AbstractHttpServerRequestHandler *handler;
};

#endif // WORKER_H
