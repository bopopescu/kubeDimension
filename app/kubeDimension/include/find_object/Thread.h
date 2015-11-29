/*

	kubeVision - OpenCV (part of the KubeVision)
	Modified by: Luc Michalski - 2015
	New features: Web-service and distributed search
	Based on: Find-Object - Mathieu Labbe - IntRoLab - Universite de Sherbrooke
	URL: https://github.com/introlab/find-object

*/
	
#ifndef THREAD_H
#define THREAD_H

#include <QtCore/QThread>

#include <Tufao/AbstractHttpServerRequestHandler>

class Thread : public QThread
{
    Q_OBJECT
public:
    explicit Thread(Tufao::AbstractHttpServerRequestHandler *handler,
                    QObject *parent = 0);

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

#endif // THREAD_H