/*

    kubeVision - OpenCV
    Modified by: Luc Michalski - 2015
    New features: Web-service and distributed search
    Based on: Find-Object - Mathieu Labbe - IntRoLab - Universite de Sherbrooke
    URL: https://github.com/introlab/find-object

*/

#ifndef SEARCH_COMMON_H
#define SEARCH_COMMON_H

#include <ios>
#include <locale>
#include <vector>
#include <string>
#include <set>
#include <functional>

namespace Common {

using Request = std::string;
using Response = std::set<std::string>;
using RequestHandler = std::function<Response(Request)>;

inline void init() noexcept {
  std::locale::global(std::locale(""));
  std::ios_base::sync_with_stdio(false);
}

inline std::vector<std::string> args(int argc, char** argv) {
  return {argv, argv + argc};
}

}

#endif
