/*

	kubeVision - OpenCV (part of the KubeVision)
	Modified by: Luc Michalski - 2015
	New features: Web-service and distributed search
	Based on: Find-Object - Mathieu Labbe - IntRoLab - Universite de Sherbrooke
	URL: https://github.com/introlab/find-object

*/
	
#ifndef HANDLERFACTORY_H
#define HANDLERFACTORY_H

#include <Tufao/AbstractHttpServerRequestHandlerFactory>

class HandlerFactory : public Tufao::AbstractHttpServerRequestHandlerFactory
{
public:
    Tufao::AbstractHttpServerRequestHandler *createHandler(QObject *parent);
};

#endif // HANDLERFACTORY_H