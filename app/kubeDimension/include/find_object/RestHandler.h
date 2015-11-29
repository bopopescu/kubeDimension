/*

	kubeVision - OpenCV
	Modified by: Luc Michalski - 2015
	New features: Web-service and distributed search
	Based on: Find-Object - Mathieu Labbe - IntRoLab - Universite de Sherbrooke
	URL: https://github.com/introlab/find-object

*/

#ifndef RESTHANDLER_H
#define RESTHANDLER_H

#include <QObject>
#include <iostream>
#include "find_object/JsonWriter.h"
#include <jsoncpp/json/json.h>

namespace Tufao {

class HttpServerRequest;
class HttpServerResponse;

} // namespace Tufao

class RestHandler : public QObject
{
    Q_OBJECT
public:
    explicit RestHandler(Tufao::HttpServerRequest *request,
                         Tufao::HttpServerResponse *response,
                         QObject *parent = 0);

private Q_SLOTS:
    void onData(const QByteArray &chunk);
    void onEnd();
    
private:
    Tufao::HttpServerRequest *request;
    Tufao::HttpServerResponse *response;
    QByteArray buffer;
    void onError(const std::ostringstream & error, Json::Value & logs);
};

#endif // RESTHANDLER_H

