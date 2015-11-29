/*

	kubeVision - OpenCV
	Modified by: Luc Michalski - 2015
	New features: Web-service and distributed search
	Based on: Find-Object - Mathieu Labbe - IntRoLab - Universite de Sherbrooke
	URL: https://github.com/introlab/find-object

*/

#ifndef SERVERHANDLER_H
#define SERVERHANDLER_H

#include <Tufao/HttpFileServer>
#include <Tufao/AbstractHttpServerRequestHandler>

class ServerHandler : public Tufao::AbstractHttpServerRequestHandler
{
    Q_OBJECT
public:
    explicit ServerHandler(QObject *parent = 0);

Q_SIGNALS:
    void newResult(QByteArray query);

public Q_SLOTS:
    bool handleRequest(Tufao::HttpServerRequest *request,
                       Tufao::HttpServerResponse *response,
                       const QStringList &args = QStringList());

protected:
    void upgrade(Tufao::HttpServerRequest *request, const QByteArray &head);
};

#endif // SERVERHANDLER_H

