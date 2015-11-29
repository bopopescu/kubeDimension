/*

    kubeVision - OpenCV
    Modified by: Luc Michalski - 2015
    New features: Web-service and distributed search
    Based on: Find-Object - Mathieu Labbe - IntRoLab - Universite de Sherbrooke
    URL: https://github.com/introlab/find-object

*/

#ifndef SEARCH_SERVICE_H
#define SEARCH_SERVICE_H

#include <string>

#include "Common.h"

namespace Service {

class Requester final {
public:
  Requester(const std::string& address, int timeout = 1000);
  ~Requester();

  // query attached services, return responses (unique, merged) for specific keyword
  Common::Response query(const std::string& keyword);

  Requester(const Requester&) = delete;
  Requester& operator=(const Requester&) = delete;

private:
  int sock_;
};


class Responder final {
public:
  Responder(const std::string& endpoint);
  ~Responder();

  // wait for requests, process them with user-provided handler
  void onRequest(Common::RequestHandler handler);

  Responder(const Responder&) = delete;
  Responder& operator=(const Responder&) = delete;

private:
  int sock_;
};

}

#endif
