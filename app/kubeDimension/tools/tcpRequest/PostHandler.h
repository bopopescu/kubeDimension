/*

	kubeVision - OpenCV
	Modified by: Luc Michalski - 2015
	New features: Web-service and distributed search
	Based on: Find-Object - Mathieu Labbe - IntRoLab - Universite de Sherbrooke
	URL: https://github.com/introlab/find-object

*/

#ifndef POSTHANDLER_H
#define POSTHANDLER_H

#include <QObject>
#include "TcpResponse.h"
#include <iostream>
#include "find_object/JsonWriter.h"
#include <jsoncpp/json/json.h>

namespace Tufao {

class HttpServerRequest;
class HttpServerResponse;

} // namespace Tufao

class PostHandler : public QObject
{
    Q_OBJECT
public:
    explicit PostHandler(Tufao::HttpServerRequest *request,
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

#endif // POSTHANDLER_H
