/*

    kubeVision - OpenCV (part of the KubeVision)
    Modified by: Luc Michalski - 2015
    New features: Web-service and distributed search
    Based on: Find-Object - Mathieu Labbe - IntRoLab - Universite de Sherbrooke
    URL: https://github.com/introlab/find-object

*/

#include "MainHandler.h"
#include "PostHandler.h"
#include <Tufao/HttpServerRequest>
#include <Tufao/Headers>
#include <QtCore/QStringList>
#include <Tufao/Url>
#include <iostream>

using namespace Tufao;
using namespace std;

MainHandler::MainHandler(QObject *parent) :
    Tufao::AbstractHttpServerRequestHandler(parent)
{
}

bool MainHandler::handleRequest(Tufao::HttpServerRequest *request,
                                Tufao::HttpServerResponse *response,
                                const QStringList &args)
{

    for (int i = 0;i != args.size();++i) {
        std::cout << args[i].toStdString().c_str() << std::endl;
    }

    if (request->method() == "POST") {

        /*
  && (   Url(request->url()).path() == "/config") ||
                                            Url(request->url()).path() == "/tree")   ||
                                            Url(request->url()).path() == "/filter") ||
                                            Url(request->url()).path() == "/batch")  ||
                                            Url(request->url()).path() == "/search") ||
                                            Url(request->url()).path() == "/add")    ||
                                            Url(request->url()).path() == "/remove") ||
                                            Url(request->url()).path() == "/vmx")
        )
        */

        PostHandler *handler = new PostHandler(request, response);
        connect(response, SIGNAL(finished()), handler, SLOT(deleteLater()));

    } else {

        response->writeHead(Tufao::HttpServerResponse::OK);
        response->headers().insert("Content-Type", "application/json");
        response->end("{\"status\": 200, \"Results\": \"kubeVision - API Index\"}");

    }

    return true;

}
