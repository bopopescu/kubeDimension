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
#include <Tufao/WebSocket>
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

    // Need to parse arguments to refine the recusive combinations

    if (request->method() == "POST" && request->url() == "/") { // For test purpose

        PostHandler *handler = new PostHandler(request, response);
        connect(response, SIGNAL(finished()), handler, SLOT(deleteLater()));

    } else if (request->url() == "/add" && request->method() == "POST") {

        response->writeHead(Tufao::HttpServerResponse::OK);
        response->headers().insert("Content-Type", "text/html; charset=utf8");
        response->end("{\"status\": 200, \"Results\": \"kubeVision - API Add a new marker \"}");

    } else if (request->url() == "/remove") {

        response->writeHead(Tufao::HttpServerResponse::OK);
        response->headers().insert("Content-Type", "text/html; charset=utf8");
        response->end("{\"status\": 200, \"Results\": \"kubeVision - API remove a marker by ID\"}");

    } else if (request->url() == "/batch") {

        response->writeHead(Tufao::HttpServerResponse::OK);
        response->headers().insert("Content-Type", "text/html; charset=utf8");
        response->end("{\"status\": 200, \"Results\": \"kubeVision - API batch upload new markers from a .zip or .tar.gz file\"}");

    } else if (request->url() == "/search") {

        response->writeHead(Tufao::HttpServerResponse::OK);
        response->headers().insert("Content-Type", "text/html; charset=utf8");
        response->end("{\"status\": 200, \"Results\": \"kubeVision - API Compare a scene to an inverted visual dictionnary\"}");

    } else if (request->url() == "/distributed_search") {

        response->writeHead(Tufao::HttpServerResponse::OK);
        response->headers().insert("Content-Type", "text/html; charset=utf8");
        response->end("{\"status\": 200, \"Results\": \"kubeVision - API Compare a scene to several inverted visual dictionnaries, with a distribution to related services\"}");

    } else if (request->url() == "/recursive_search") {

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

void MainHandler::upgrade(Tufao::HttpServerRequest *request,
                          const QByteArray &head)
{
    if (request->url() != "/client") {
        Tufao::HttpServerResponse response(request->socket(),
                                           request->responseOptions());
        response.writeHead(Tufao::HttpServerResponse::OK);
        response.headers().insert("Content-Type", "application/json");
        response.end("{\"status\": 200, \"Results\": \"kubeVision - API Index\"}");
        return; 
    }

    Tufao::WebSocket *socket = new Tufao::WebSocket(this);
    socket->startServerHandshake(request, head);
    socket->setMessagesType(Tufao::WebSocket::BINARY_MESSAGE); // We exchange JPEGs or PNGs files mainly

    connect(socket, SIGNAL(disconnected()), socket, SLOT(deleteLater()));

    connect(socket, SIGNAL(newMessage(QByteArray)),
            this, SIGNAL(newMessage(QByteArray)));
    connect(this, SIGNAL(newMessage(QByteArray)),
            socket, SLOT(sendMessage(QByteArray)));
}
