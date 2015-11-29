/*

	kubeVision - OpenCV
	Modified by: Luc Michalski - 2015
	New features: Web-service and distributed search
	Based on: Find-Object - Mathieu Labbe - IntRoLab - Universite de Sherbrooke
	URL: https://github.com/introlab/find-object

*/

#include "find_object/utilite/ULogger.h"
#include "find_object/MainHandler.h"
//#include "find_object/RestHandler.h"
#include <Tufao/HttpServerRequest>
#include <Tufao/Headers>
    
MainHandler::MainHandler(QObject *parent) :
    Tufao::AbstractHttpServerRequestHandler(parent)
{
}

bool MainHandler::handleRequest(Tufao::HttpServerRequest *request,
                                Tufao::HttpServerResponse *response,
                                const QStringList &args)
{

    // Loop over the arguments received
    for (int i = 0;i != args.size();++i) {
        // Displat the arguments intercepted
        UINFO("Parameters received: %s", args[i].toStdString().c_str());
    }

    // Need to parse arguments to refine the recusive combinations
    // Intercept POST Method
    if (request->method() == "POST" && request->url() == "/") { // For test purpose

//        RestHandler *handler = new RestHandler(request, response);
//        connect(response, SIGNAL(finished()), handler, SLOT(deleteLater()));

    } else if (request->url() == "/add" && request->method() == "POST") {

        response->writeHead(Tufao::HttpServerResponse::OK);
        response->headers().insert("Content-Type", "text/html; charset=utf8");
        response->end("{\"status\": 200, \"Results\": \"kubeVision - API Add a new marker \"}");

    } else if (request->url() == "/remove" && request->method() == "GET") {

        response->writeHead(Tufao::HttpServerResponse::OK);
        response->headers().insert("Content-Type", "text/html; charset=utf8");
        response->end("{\"status\": 200, \"Results\": \"kubeVision - API remove a marker by ID\"}");

    } else if (request->url() == "/batch" && request->method() == "POST") {

        response->writeHead(Tufao::HttpServerResponse::OK);
        response->headers().insert("Content-Type", "text/html; charset=utf8");
        response->end("{\"status\": 200, \"Results\": \"kubeVision - API batch upload new markers from a .zip or .tar.gz file\"}");

    } else if (request->url() == "/search" && request->method() == "POST") {

        response->writeHead(Tufao::HttpServerResponse::OK);
        response->headers().insert("Content-Type", "text/html; charset=utf8");
        response->end("{\"status\": 200, \"Results\": \"kubeVision - API Compare a scene to an inverted visual dictionnary\"}");

    } else if (request->url() == "/distributed_search" && request->method() == "POST") {

        response->writeHead(Tufao::HttpServerResponse::OK);
        response->headers().insert("Content-Type", "text/html; charset=utf8");
        response->end("{\"status\": 200, \"Results\": \"kubeVision - API Compare a scene to several inverted visual dictionnaries, with a distribution to related services\"}");

    } else if (request->url() == "/recursive_search" && request->method() == "POST") {

        response->writeHead(Tufao::HttpServerResponse::OK);
        response->headers().insert("Content-Type", "text/html; charset=utf8");
        response->end("{\"status\": 200, \"Results\": \"kubeVision - API Compare a scene to several inverted visual dictionnary, with a distribution to related services with a recursive tree\"}");

    } else {

        response->writeHead(Tufao::HttpServerResponse::OK);
        response->headers().insert("Content-Type", "application/json");
        response->end("{\"status\": 200, \"Results\": \"kubeVision - API Index\"}");

    }

    return true;

}