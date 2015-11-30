/*

	kubeVision - OpenCV (part of the KubeVision)
	Modified by: Luc Michalski - 2015
	New features: Web-service and distributed search
	Based on: Find-Object - Mathieu Labbe - IntRoLab - Universite de Sherbrooke
	URL: https://github.com/introlab/find-object

*/

#include <QCoreApplication>
#include <QtCore/QRegExp>
#include <Tufao/HttpServer>
#include <Tufao/HttpServerRequestRouter>
#include <Tufao/HttpPluginServer>
#include "MainHandler.h"
#include "find_object/utilite/ULogger.h"
#include "find_object/JsonWriter.h"
#include "TcpResponse.h"
#include "services/Common.h"
#include "services/Service.h"
#include "find_object/TcpServer.h"
#include "find_object/HandlerFactory.h"

// HiRedis
#include <iostream>
#include <iomanip>
#include <QtCore/QTimer>
#include "find_object/RedisQt.h"

// Etcd 2.0 [Required for the kubeProxy backends/frontends mapping]
//#include "etcd/Client.hpp"

bool running = true;
using namespace std;

#ifdef WIN32
#include <windows.h> 
BOOL WINAPI my_handler(DWORD signal)
{
    if (signal == CTRL_C_EVENT)
	{
        printf("\nCtrl-C caught! Quitting application...\n");
		QCoreApplication::quit();
	}
    return TRUE;
    running = false;
}
#else
#include <signal.h>
void my_handler(int s)
{
	printf("\nCtrl-C caught! Quitting application...\n");
	QCoreApplication::quit();
	running = false;
}
inline void Sleep(unsigned int ms)
{
	struct timespec req;
	struct timespec rem;
	req.tv_sec = ms / 1000;
	req.tv_nsec = (ms - req.tv_sec * 1000) * 1000 * 1000;
	nanosleep (&req, &rem);
}
#endif

void setupQuitSignal()
{
// Catch ctrl-c to close Qt
#ifdef WIN32
	if (!SetConsoleCtrlHandler(my_handler, TRUE))
	{
		UERROR("Could not set control (ctrl-c) handler");
	}
#else
	struct sigaction sigIntHandler;
	sigIntHandler.sa_handler = my_handler;
	sigemptyset(&sigIntHandler.sa_mask);
	sigIntHandler.sa_flags = 0;
	sigaction(SIGINT, &sigIntHandler, NULL);
#endif
}

void getCallback(redisAsyncContext *, void * r, void * privdata) {

    redisReply * reply = static_cast<redisReply *>(r);
    QtRedis * ex = static_cast<QtRedis *>(privdata);
    if (reply == nullptr || ex == nullptr) return;
    // to change for UINFO messaging
    cout << "key: " << reply->str << endl;

    ex->finish();
}

void QtRedis::run() {

    m_ctx = redisAsyncConnect("localhost", 6379);

    if (m_ctx->err) {
        cerr << "Error: " << m_ctx->errstr << endl;
        redisAsyncFree(m_ctx);
        Q_EMIT finished();
    }

    m_adapter.setContext(m_ctx);

    redisAsyncCommand(m_ctx, NULL, NULL, "SET key %s", m_value);
    redisAsyncCommand(m_ctx, getCallback, this, "GET key");
}

void showUsage()
{
	printf("kubeVision - Recursively Building Visual Discovery Service Trees. Start command (eg): \n"
			"   1. tcpRequest [options] --httpPort 18080 --httpHost 192.168.0.1 \n"
			"   2. tcpRequest [options] --httpPort 18080 --httpHost 192.168.0.1 --tcpDistSearchPort 8500 --tcpDistSearchHost 192.168.0.1 \n"
			"   3. tcpRequest [options] --httpPort 1981 --httpHost 127.0.0.1 --tcpClientPort 1986 (<= the response, eg JSON) --tcpServerPort 1979 (=> buffer with the encoded image in PNG Format) \n"
			"  \n"
			" Web Service parameters:"
			"  \"httpPort\" is the port where the webservice will be running.\n"
			"  \"httpHost\" is the host where the webservice will be reachable.\n"
			"  \n"
			" Internal TCP Services:"
//			"  \"tcpClientPort\" is the port from which the detection information is received.\n"
//			"  \"tcpClientHost\" is the hostaddress from which the detection information is received.\n"
			"  \"tcpDistSearchPort\" is the port from which we can trigger a distributed search with nano messages.\n"
			"  \"tcpDistSearchHost\" is the port from which we can trigger a distributed search with nano messages.\n"
//			"  \"tcpServerPort\" is the port to which the image is sent to a Visual TCP Server.\n"
//			"  \"tcpServerHost\" is the hostaddress to which the image is sent to a Visual TCP Server.\n"
			"  \n"
			"  Options:\n"
			"    --json       output JSON file.\n"
			"    --xml        output XML file.\n"
			"    --threads    Only 1 by default (Need to be developed).\n"
			"    --help       Show this help.\n"
			"  \n"
			"  Service Tree Mapping:\n"
			"  ./VisualSearch \"tcp://*:9995\"\n"
			"  ./Cache \"tcp://localhost:9995\"\n"
			"  ./RecursiveVisualSearch \"tcp://*:9996\" \"tcp://localhost:9995\"\n"
			"  ./Centroid1 \"tcp://localhost:9996\"\n"
			"  ./Centroid2 \"tcp://localhost:9996\"\n"
			"  \n"
			"  Service Trees Graph:\n"
			"         VisualSearch\n"
			"        /          \\    \n"
			"  Visual Cache  RecursiveVisualSearch\n"
			"                   /              \\    \n"
			"       		Centroid1        Centroid2\n"
			"\n");
}

int main(int argc, char * argv[])
{
	ULogger::setType(ULogger::kTypeConsole);
	ULogger::setLevel(ULogger::kInfo);
	ULogger::setPrintWhere(false);
	ULogger::setPrintTime(false);

	quint16 httpPort 			= 8080; // WebService Port for the REST API
	//quint16 tcpServerPort 		= 1979; // TCP Server with an inverted vocabulary
	//quint16 tcpClientPort 		= 1986; // Port where to receive the response
	quint16 tcpDistSearchPort	= 1986; // Port where to send a scene for a distributed search

	QString httpHost 			= "127.0.0.1"; // Public host for the Web Service
	//QString tcpServerHost 		= "127.0.0.1"; // Visual inverted dictionary host
	//QString tcpClientHost 		= "127.0.0.1"; // Reception of the answer host
	QString tcpDistSearchHost 	= "127.0.0.1"; // Distributed search host

	// Parse Options
	for(int i=1; i<argc; ++i)
	{

		if(strcmp(argv[i], "--httpPort") == 0 || strcmp(argv[i], "-httpPort") == 0)
		{
			++i;
			if(i < argc)
			{
				httpPort = std::atoi(argv[i]);
				UINFO("httpPort: \"%d\"", httpPort);
			}
			else
			{
				printf("error parsing --httpPort\n");
				showUsage();
			}
			continue;
		}

		if(strcmp(argv[i], "--httpHost") == 0 || strcmp(argv[i], "-httpHost") == 0)
		{
			++i;
			if(i < argc)
			{
				httpHost = argv[i];
				UINFO("httpHost: \"%s\"", httpHost.toStdString().c_str());
			}
			else
			{
				printf("error parsing --httpHost\n");
				showUsage();
			}
			continue;
		}

		if(strcmp(argv[i], "--tcpDistSearchPort") == 0 || strcmp(argv[i], "-tcpDistSearchPort") == 0)
		{
			++i;
			if(i < argc)
			{
				tcpDistSearchPort = std::atoi(argv[i]);
				UINFO("tcpDistSearchPort: \"%d\"", tcpDistSearchPort);
			}
			else
			{
				printf("error parsing --tcpDistSearchPort\n");
				showUsage();
			}
			continue;
		}

		if(strcmp(argv[i], "--tcpDistSearchHost") == 0 || strcmp(argv[i], "-tcpDistSearchHost") == 0)
		{
			++i;
			if(i < argc)
			{
				tcpDistSearchHost = argv[i];
				UINFO("tcpDistSearchHost: \"%s\"", tcpDistSearchHost.toStdString().c_str());
			}
			else
			{
				printf("error parsing --tcpDistSearchHost\n");
				showUsage();
			}
			continue;
		}

	}

//	QEventDispatcherEpoll epollDispatcher;
	QCoreApplication app(argc, argv);

	// Store some key/values into HiRedis
    QtRedis rstorage(argv[argc-1]);

    // Connect SLOTS and SIGNALS with the REDIS STORE
    QObject::connect(&rstorage, SIGNAL(finished()), &app, SLOT(quit()));
    QTimer::singleShot(0, &rstorage, SLOT(run()));

//    Tufao::HttpServer server;
//    Tufao::HttpServerRequestRouter router;
//    MainHandler h;

    // Show the usage
	// showUsage();

    // Routes parser
    //router.map(QRegExp("^/([^/]+)$"), &h).map(QRegExp(".*"), &h);

    // Visual Recognition Middleware
    //QObject::connect(&server, SIGNAL(requestReady(Tufao::HttpServerRequest*,Tufao::HttpServerResponse*)),
    //                 &h, SLOT(handleRequest(Tufao::HttpServerRequest*,Tufao::HttpServerResponse*)));

    // Start the server
    //server.listen(QHostAddress::LocalHost, httpPort);

   	TcpServer server;

    server.run(4, 5000, new HandlerFactory);
 	// threads to implement in the next commit
	// server.run(4, 8080, new HandlerFactory);    

    // Quit signals, so we can do some backups before closing the service
	// setupQuitSignal();

    return app.exec();

}

