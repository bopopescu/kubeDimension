/*

	kubeVision - OpenCV
	Modified by: Luc Michalski - 2015
	New features: Web-service and distributed search
	Based on: Find-Object - Mathieu Labbe - IntRoLab - Universite de Sherbrooke
	URL: https://github.com/introlab/find-object

*/

#ifndef MAINHANDLER_H
#define MAINHANDLER_H

#include <Tufao/AbstractHttpServerRequestHandler>
#include <QtCore/QObject>
#include <QtCore/QByteArray>

class MainHandler : public Tufao::AbstractHttpServerRequestHandler
{
    Q_OBJECT
public:
    explicit MainHandler(QObject *parent = 0);

public Q_SLOTS:
    bool handleRequest(Tufao::HttpServerRequest *request,
                       Tufao::HttpServerResponse *response,
                       const QStringList &args);
};
#endif // MAINHANDLER_H