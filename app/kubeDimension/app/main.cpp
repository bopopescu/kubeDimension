/*

	kubeVision - OpenCV
	Modified by: Luc Michalski - 2015
	New features: Web-service and distributed search
	Based on: Find-Object - Mathieu Labbe - IntRoLab - Universite de Sherbrooke
	URL: https://github.com/introlab/find-object

*/

#include <QtCore/QCoreApplication>
#include <QtCore/QDir>
#include <QtCore/QFile>
#include <QtCore/QTime>
#include <QtCore/QStringList>
#include <iostream>
#include <iomanip>
#include <sys/stat.h>

// JPEG Exif Metas data extractor
#include "find_object/Exif.h"

#include "find_object/Settings.h"
//#include "find_object/TcpServer.h"

// Mutli-threaded Web Service
#include "find_object/TcpServer.h"
#include "find_object/HandlerFactory.h"

// Post Data handler
//#include "find_object/ServerHandler.h"
//#include "find_object/RestHandler.h"

// Multi-Threaded FindObject
#include "find_object/FindObject.h"
//#include "find_object/KubeServer.h"
//#include "find_object/KubeThread.h"

// Utils to transform output
#include "find_object/JsonWriter.h"

// Loggin librairies
#include "find_object/utilite/ULogger.h"

// Distributed Search with IPC Protocol	
#include "find_object/Common.h"
#include "find_object/Service.h"

// HiRedis
#include <QtCore/QTimer>
#include "find_object/RedisQt.h"

bool running = true;

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

void showUsage()
{
	printf("\nUsage:\n"
#ifdef WIN32
			"  Find-Object.exe [options]\n"
#else
			"  find_object [options]\n"
#endif
			"Options:\n"
			"  --session \"path\"       Path to a session to load (*.bin). Use \"--session_new\" to\n"
			"                           create a session instead (will be saved to \"path\" on exit, only\n"
			"                           on console mode).\n"
			"  --object \"path\"        Path to an object to detect.\n"
			"  --objects \"path\"       Directory of the objects to detect (--object is ignored).\n"
			"  --config \"path\"        Path to configuration file (default: %s).\n"
			"                           If set to \"\", default parameters are used\n"
			"                           without saving modified parameters on closing.\n"
			"  --shards 1         		How many shards (increment +1 from port 1979).\n"
			"  --replicas 1         	How many replicas ? Loaded from the yaml generated, so readonly (increment +1 from port 3000).\n"
			"  --scene \"path\"         Path to a scene image file.\n"
			"  --scene \"path\"         Path to a scene image file.\n"
			"  --vocabulary \"path\"    Path to a vocabulary file (*.yaml *.xml). Parameters \"General/invertedSearch\"\n"
			"                           and \"General/vocabularyFixed\" will be also enabled. Ignored if \"--session\" is set.\n"
			"  --images_not_saved     Don't keep images in RAM after the features are extracted (only\n"
			"                           in console mode). Images won't be saved if an output session is set.\n"
			"  --debug                Show debug log.\n"
			"  --debug-time           Show debug log with time.\n"
			"  --params               Show all parameters.\n"
			"  --defaults             Use default parameters (--config is ignored).\n"
			"  --My/Parameter \"value\" Set find-Object's parameter (look --params for parameters' name).\n"
			"                           It will override the one in --config. Example to set 4 threads:\n"
			"                           $ find_object --General/threads 4\n"
			"  --help                 Show usage.\n"
			, find_object::Settings::iniDefaultPath().toStdString().c_str());
	exit(-1);
}

using namespace std;

string convertToString(double num) {
    ostringstream convert;
    convert << num; 
    return convert.str();
}

double roundOff(double n) {
    double d = n * 100.0;
    int i = d + 0.5;
    d = (float)i / 100.0;
    return d;
}

string convertSize(size_t size) {               
    static const char *SIZES[] = { "B", "KB", "MB", "GB" };
    u_int div = 0;
    size_t rem = 0;

    while (size >= 1024 && div < (sizeof SIZES / sizeof *SIZES)) {
        rem = (size % 1024);
        div++;
        size /= 1024;
    }

    double size_d = (float)size + (float)rem / 1024.0;
    string result = convertToString(roundOff(size_d)) + " " + SIZES[div];
    return result;
}

int file_size(const char *path) {
    struct stat results;

    if (stat(path, &results) == 0) {
        return results.st_size;
    } else {
        return -1;
    }
}

// This is the function that you will call:
string getFileSize(string path) {
    size_t size = file_size((const char *)path.c_str());
    return convertSize(size);
}

/*
static void onInteraction(Common::RequestHandler);

static void onInteraction(Common::RequestHandler handler) {
	std::string request;
	do {
		if (!request.empty()) {
		  const auto responses = handler(request);

	  std::cout << "\nResults>\n";
	  for (auto&& resp : responses)
	    std::cout << " * " << resp << '\n';
	}
		std::cout << "\nSearch>" << std::endl;
	} while (std::getline(std::cin, request));
}
*/

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

int main(int argc, char* argv[])
{
	ULogger::setType(ULogger::kTypeConsole);
	ULogger::setLevel(ULogger::kInfo);
	ULogger::setPrintWhere(false);
	ULogger::setPrintTime(false);

	//////////////////////////
	// parse options BEGIN
	//////////////////////////
	QString sessionPathTemp = "./tempSession.bin";
	QString vocPathTemp = "./tempVoc.yaml";
	QString sessionPath = "";
	bool sessionNew = false;
	bool recursive = false;
	bool keepImagesInRAM = false;
	bool distributedSearch = false;
	int shards = 1;
	int replicas = 1;
	int replicasPortStart 	= 3000;
	int shardsPortStart 	= 2000;
	int workersCopy = 1;
	int workersShards = 1;

	QString objectsPath = "";
	QString objectPath = "";
	QString scenePath = "";
	std::string sessionFileSize;
	std::string vocFileSize;
	std::ostringstream sessionSize;
	std::ostringstream vocSize;
	QString configPath = find_object::Settings::iniDefaultPath();
	QString vocabularyPath = "";
	QString jsonPath;
	find_object::ParametersMap customParameters;
	bool imagesSaved = true;

	for(int i=1; i<argc; ++i)
	{
#ifdef __APPLE__
		if(QString(argv[i]).startsWith("-psn"))
		{
			//safely ignore
			continue;
		}
#endif
		if(strcmp(argv[i], "-objs") == 0 ||
		   strcmp(argv[i], "--objs") == 0 ||
		   strcmp(argv[i], "-objects") == 0 ||
		   strcmp(argv[i], "--objects") == 0)
		{
			++i;
			if(i < argc)
			{
				objectsPath = argv[i];
				if(objectsPath.contains('~'))
				{
					objectsPath.replace('~', QDir::homePath());
				}
				if(!QDir(objectsPath).exists())
				{
					UERROR("Objects path not valid : %s", objectsPath.toStdString().c_str());
					showUsage();
				}
			}
			else
			{
				showUsage();
			}
			continue;
		}

		if(strcmp(argv[i], "--shards") == 0 || strcmp(argv[i], "-shards") == 0)
		{
			++i;
			if(i < argc)
			{
				shards = std::atoi(argv[i]);
				UINFO("shards: \"%d\"", shards);
			}
			else
			{
				printf("error parsing --shards\n");
				showUsage();
			}
			continue;
		}

		if(strcmp(argv[i], "--replicas") == 0 || strcmp(argv[i], "-replicas") == 0)
		{
			++i;
			if(i < argc)
			{
				replicas = std::atoi(argv[i]);
				UINFO("replicas: \"%d\"", replicas);
			}
			else
			{
				printf("error parsing --replicas\n");
				showUsage();
			}
			continue;
		}		

		if(strcmp(argv[i], "-session") == 0 ||
		   strcmp(argv[i], "--session") == 0 ||
		   strcmp(argv[i], "-session_new") == 0 ||
		   strcmp(argv[i], "--session_new") == 0)
		{
			if(strcmp(argv[i], "-session_new") == 0 ||
			   strcmp(argv[i], "--session_new") == 0)
			{
				sessionNew = true;
			}
			++i;
			if(i < argc)
			{
				sessionPath = argv[i];
				if(sessionPath.contains('~'))
				{
					sessionPath.replace('~', QDir::homePath());
				}

				if(!sessionNew && !QFile(sessionPath).exists())
				{
					UERROR("Session path not valid : %s (if you want to create a new session, use \"--session_new\")", sessionPath.toStdString().c_str());
					showUsage();
				}
			}
			else
			{
				showUsage();
			}
			continue;
		}
		if(strcmp(argv[i], "-object") == 0 ||
		   strcmp(argv[i], "--object") == 0)
		{
			++i;
			if(i < argc)
			{
				objectPath = argv[i];
				if(objectPath.contains('~'))
				{
					objectPath.replace('~', QDir::homePath());
				}
				if(!QFile(objectPath).exists())
				{
					UERROR("Object path not valid : %s", objectPath.toStdString().c_str());
					showUsage();
				}
			}
			else
			{
				showUsage();
			}
			continue;
		}
		if(strcmp(argv[i], "-scene") == 0 ||
		   strcmp(argv[i], "--scene") == 0)
		{
			++i;
			if(i < argc)
			{
				scenePath = argv[i];
				if(scenePath.contains('~'))
				{
					scenePath.replace('~', QDir::homePath());
				}
				if(!QFile(scenePath).exists())
				{
					UERROR("Scene path not valid : %s", scenePath.toStdString().c_str());
					showUsage();
				}
			}
			else
			{
				showUsage();
			}
			continue;
		}
		if(strcmp(argv[i], "-vocabulary") == 0 ||
		   strcmp(argv[i], "--vocabulary") == 0)
		{
			++i;
			if(i < argc)
			{
				vocabularyPath = argv[i];
				if(vocabularyPath.contains('~'))
				{
					vocabularyPath.replace('~', QDir::homePath());
				}
				if(!QFile(vocabularyPath).exists())
				{
					UERROR("Vocabulary path not valid : %s", vocabularyPath.toStdString().c_str());
					showUsage();
				}
			}
			else
			{
				showUsage();
			}
			continue;
		}
		if(strcmp(argv[i], "-config") == 0 ||
		   strcmp(argv[i], "--config") == 0)
		{
			++i;
			if(i < argc)
			{
				configPath = argv[i];
				if(configPath.contains('~'))
				{
					configPath.replace('~', QDir::homePath());
				}
				if(!configPath.isEmpty() && !QFile::exists(configPath))
				{
					UWARN("Configuration file \"%s\" doesn't exist, it will be created with default values...", configPath.toStdString().c_str());
				}
			}
			else
			{
				showUsage();
			}
			continue;
		}
		if(strcmp(argv[i], "-recursive") == 0 ||
		   strcmp(argv[i], "--recursive") == 0)
		{
			recursive = true;
			continue;
		}
		if(strcmp(argv[i], "-images_not_saved") == 0 ||
		   strcmp(argv[i], "--images_not_saved") == 0)
		{
			imagesSaved = false;
			continue;
		}
		if(strcmp(argv[i], "-debug") == 0 ||
		   strcmp(argv[i], "--debug") == 0)
		{
			ULogger::setPrintWhere(true);
			ULogger::setLevel(ULogger::kDebug);
			continue;
		}
		if(strcmp(argv[i], "-debug-time") == 0 ||
		   strcmp(argv[i], "--debug-time") == 0)
		{
			ULogger::setPrintWhere(true);
			ULogger::setLevel(ULogger::kDebug);
			ULogger::setPrintTime(true);
			continue;
		}
		if(strcmp(argv[i], "-help") == 0 ||
		   strcmp(argv[i], "--help") == 0)
		{
			showUsage();
		}
		if(strcmp(argv[i], "-json") == 0 ||
		   strcmp(argv[i], "--json") == 0)
		{
			++i;
			if(i < argc)
			{
				jsonPath = argv[i];
				if(jsonPath.contains('~'))
				{
					jsonPath.replace('~', QDir::homePath());
				}
			}
			else
			{
				showUsage();
			}
			continue;
		}
		if(strcmp(argv[i], "--params") == 0)
		{
			find_object::ParametersMap parameters = find_object::Settings::getDefaultParameters();
			for(find_object::ParametersMap::iterator iter=parameters.begin(); iter!=parameters.end(); ++iter)
			{
				std::string str = "Param: " + iter.key().toStdString() + " = \"" + iter.value().toString().toStdString() + "\"";
				std::cout <<
						str <<
						std::setw(60 - str.size()) <<
						" [" <<
						find_object::Settings::getDescriptions().value(iter.key()).toStdString().c_str() <<
						"]" <<
						std::endl;
			}
			UINFO("Node will now exit after showing default Find-Object's parameters because "
					 "argument \"--params\" is detected!");
			exit(0);
		}

		// Check for custom parameters:
		find_object::ParametersMap parameters = find_object::Settings::getDefaultParameters();
		QString name = argv[i];
		if(name.size() > 2)
		{
			//strip the "--"
			name.remove(0, 2);
			if(parameters.contains(name))
			{
				++i;
				if(i < argc)
				{
					customParameters.insert(name, argv[i]);
				}
				else
				{
					showUsage();
				}
				continue;
			}
		}

		UERROR("Unrecognized option : %s", argv[i]);
		showUsage();
	}

	UINFO("Options:");
	if(!sessionPath.isEmpty())
	{
		if(sessionNew)
		{
			UINFO("   Session path: \"%s\" [NEW]", sessionPath.toStdString().c_str());
		}
		else
		{
			UINFO("   Session path: \"%s\"", sessionPath.toStdString().c_str());
		}
	}
	else if(!objectsPath.isEmpty())
	{
		UINFO("   Objects path: \"%s\"", objectsPath.toStdString().c_str());
	}
	else if(!objectPath.isEmpty())
	{
		UINFO("   Object path: \"%s\"", objectPath.toStdString().c_str());
	}
	UINFO("   Scene path: \"%s\"", scenePath.toStdString().c_str());
	UINFO("   Settings path: \"%s\"", configPath.toStdString().c_str());
	UINFO("   Vocabulary path: \"%s\"", vocabularyPath.toStdString().c_str());

	if(!vocabularyPath.isEmpty())
	{
		if(customParameters.contains(find_object::Settings::kGeneral_vocabularyFixed()))
		{
			UWARN("\"General/vocabularyFixed\" custom parameter overwritten as a fixed vocabulary is used.");
		}
		if(customParameters.contains(find_object::Settings::kGeneral_invertedSearch()))
		{
			UWARN("\"General/invertedSearch\" custom parameter overwritten as a fixed vocabulary is used.");
		}
		customParameters[find_object::Settings::kGeneral_vocabularyFixed()] = true;
		customParameters[find_object::Settings::kGeneral_invertedSearch()] = true;
	}

	for(find_object::ParametersMap::iterator iter= customParameters.begin(); iter!=customParameters.end(); ++iter)
	{
		UINFO("   Param \"%s\"=\"%s\"", iter.key().toStdString().c_str(), iter.value().toString().toStdString().c_str());
	}

	//////////////////////////
	// parse options END
	//////////////////////////

	// Load settings, should be loaded before creating other objects
	find_object::Settings::init(configPath);

	// Override custom parameters:
	for(find_object::ParametersMap::iterator iter= customParameters.begin(); iter!=customParameters.end(); ++iter)
	{
		find_object::Settings::setParameter(iter.key(), iter.value());
	}

	// Create FindObject
	UINFO("Shards: %d ", shards);
	UINFO("Shards Port Start: %d ", shardsPortStart);
	UINFO("Replicas: %d ", replicas);
	UINFO("Replicas Port Start: %d ", replicasPortStart);

	// arg1: keepImagesInRAM=true
	// arg2: distributedSearch=false
	// arg3: workersCopy=4
	// arg4: workersShards=4

	find_object::FindObject * findObject = new find_object::FindObject(keepImagesInRAM || distributedSearch || workersCopy || workersShards || imagesSaved);

	/*
	for( int a = 0; a < shards; a = a + 1 )
	{	
		find_object::TcpServer tcpServer(shardsPortStart);
		find_object::FindObject * findObject[shardsPortStart] = new find_object::FindObject(guiMode || imagesSaved);
		shardsPortStart += 1;
	}
	*/

	// Load objects if path is set
	int objectsLoaded = 0;
	if(!sessionPath.isEmpty() && !sessionNew)
	{
		if(!vocabularyPath.isEmpty() && !findObject->loadVocabulary(vocabularyPath))
		{
			UWARN("Vocabulary \"%s\" is not loaded as a session \"%s\" is already loaded",
					vocabularyPath.toStdString().c_str(),
					sessionPath.toStdString().c_str());
		}
		if(!findObject->loadSession(sessionPath))
		{
			UERROR("Could not load session \"%s\"", sessionPath.toStdString().c_str());
		}
		else
		{
			objectsLoaded = findObject->objects().size();
		}
	}
	else if(!objectsPath.isEmpty())
	{
		if(!vocabularyPath.isEmpty() && !findObject->loadVocabulary(vocabularyPath))
		{
			UERROR("Failed to load vocabulary \"%s\"", vocabularyPath.toStdString().c_str());
		}
		objectsLoaded = findObject->loadObjects(objectsPath, recursive);
		if(!objectsLoaded)
		{
			UWARN("No objects loaded from \"%s\"", objectsPath.toStdString().c_str());
		}
	}
	else if(!objectPath.isEmpty())
	{
		if(!vocabularyPath.isEmpty() && !findObject->loadVocabulary(vocabularyPath))
		{
			UERROR("Failed to load vocabulary \"%s\"", vocabularyPath.toStdString().c_str());
		}

		const find_object::ObjSignature * obj = findObject->addObject(objectPath);
		if(obj)
		{
			++objectsLoaded;
			findObject->updateObjects();
			findObject->updateVocabulary();
		}
		else
		{
			UWARN("No object loaded from \"%s\"", objectsPath.toStdString().c_str());
		}
	}
	else if(!vocabularyPath.isEmpty() && !findObject->loadVocabulary(vocabularyPath))
	{
		UERROR("Failed to load vocabulary \"%s\"", vocabularyPath.toStdString().c_str());
	}

	cv::Mat scene;
	if(!scenePath.isEmpty())
	{
		scene = cv::imread(scenePath.toStdString());
		if(scene.empty())
		{
			UERROR("Failed to load scene \"%s\"", scenePath.toStdString().c_str());
		}
	}

	// Check if we have some parallel computing librairies installed
	#ifdef HAVE_TBB
	    UINFO("Running with TBB");
	#else
	#ifdef _OPENMP
	    UINFO("Running with OpenMP");
	#else
	    UINFO("Running without OpenMP and without TBB");
	#endif
	#endif

	// Accelrate TCP based exchanges
//	QEventDispatcherEpoll epollDispatcher;
	QCoreApplication app(argc, argv);

	// Store some key/values into HiRedis
    QtRedis rstorage(argv[argc-1]);

    // Connect SLOTS and SIGNALS with the REDIS STORE
    QObject::connect(&rstorage, SIGNAL(finished()), &app, SLOT(quit()));
    QTimer::singleShot(0, &rstorage, SLOT(run()));

	/*
	if(!scene.empty())
	{
		// process the scene and exit
		QTime time;
		time.start();
		find_object::DetectionInfo info;
		findObject->detect(scene, info);

		if(info.objDetected_.size() > 1)
		{
			UINFO("%d objects detected! (%d ms)", (int)info.objDetected_.size(), time.elapsed());
		}
		else if(info.objDetected_.size() == 1)
		{
			UINFO("Object %d detected! (%d ms)", (int)info.objDetected_.begin().key(), time.elapsed());
		}
		else if(find_object::Settings::getGeneral_sendNoObjDetectedEvents())
		{
			UINFO("No objects detected. (%d ms)", time.elapsed());
		}

		if(!jsonPath.isEmpty())
		{
			find_object::JsonWriter::write(info, jsonPath);
			UINFO("JSON written to \"%s\"", jsonPath.toStdString().c_str());
		}
	}
	else
	{*/
	//find_object::TcpServer tcpServer(find_object::Settings::getGeneral_port());
	//UINFO("Detection sent on port: %d (IP=%s)", tcpServer.getPort(), tcpServer.getHostAddress().toString().toStdString().c_str());

	// [FindObject] ---ObjectsDetected---> [TcpServer]
	//QObject::connect(findObject, SIGNAL(objectsFound(find_object::DetectionInfo)), &tcpServer, SLOT(publishDetectionInfo(find_object::DetectionInfo)));
	//QObject::connect(&tcpServer, SIGNAL(detectObject(const cv::Mat &)), findObject, SLOT(detect(const cv::Mat &)));

	//connect services
	//QObject::connect(&tcpServer, SIGNAL(addObject(const cv::Mat &, int, const QString &)), findObject, SLOT(addObjectAndUpdate(const cv::Mat &, int, const QString &)));
	//QObject::connect(&tcpServer, SIGNAL(removeObject(int)), findObject, SLOT(removeObjectAndUpdate(int)));

	//use camera in settings
    //KubeServer kube;
    //MainHandler h;
  	setupQuitSignal();

	// Singleton  
	// Tufao::HttpServer server;

	// QObject::connect(&server, SIGNAL(requestReady(Tufao::HttpServerRequest*,Tufao::HttpServerResponse*)),
	//                  &h, SLOT(handleRequest(Tufao::HttpServerRequest*,Tufao::HttpServerResponse*)));  
	// server.listen(QHostAddress::LocalHost, 8081);

    //

	//kube.run(4, QHostAddress::LocalHost, 8081, new HandlerFactory);
	// Distributed Search

	/*
	Common::init();
	const auto args = Common::args(argc, argv);

	Service::Requester self{endpoint};

	const auto handler = [&self](const Common::Request& req) -> Common::Response {
		return self.query(req);
	};

	onInteraction(handler);

	if(findObject->saveSession(sessionPathTemp))
	{
		sessionSize << getFileSize(sessionPathTemp.toStdString().c_str());
		sessionFileSize =  sessionSize.str();
		UINFO("Session \"%s\" successfully saved (%d objects), for a size of %s",
				sessionPathTemp.toStdString().c_str(), findObject->objects().size(), sessionFileSize.c_str());
	}
	*/

	if(findObject->saveVocabulary(vocPathTemp))
	{
		vocSize << getFileSize(vocPathTemp.toStdString().c_str());
		vocFileSize =  vocSize.str();
		UINFO("Session \"%s\" successfully saved (%d objects), for a size of %s",
				vocPathTemp.toStdString().c_str(), findObject->objects().size(), vocFileSize.c_str());
	}

	if(running)
	{
	    TcpServer server;
		server.run(4, 8080, new HandlerFactory);
		app.exec();

		if(findObject->saveVocabulary(vocPathTemp))
		{
			vocSize << getFileSize(sessionPathTemp.toStdString().c_str());
			vocFileSize =  vocSize.str();
			UINFO("Session \"%s\" successfully saved (%d objects), for a size of %s",
					vocPathTemp.toStdString().c_str(), findObject->objects().size(), vocFileSize.c_str());
		}

		delete findObject;

	} else {

		delete findObject;		

	}

}
