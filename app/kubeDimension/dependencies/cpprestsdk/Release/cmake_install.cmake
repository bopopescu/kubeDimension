# Install script for directory: /src/app/find-object/dependencies/cpprestsdk/Release

# Set the install prefix
if(NOT DEFINED CMAKE_INSTALL_PREFIX)
  set(CMAKE_INSTALL_PREFIX "/usr/local")
endif()
string(REGEX REPLACE "/$" "" CMAKE_INSTALL_PREFIX "${CMAKE_INSTALL_PREFIX}")

# Set the install configuration name.
if(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)
  if(BUILD_TYPE)
    string(REGEX REPLACE "^[^A-Za-z0-9_]+" ""
           CMAKE_INSTALL_CONFIG_NAME "${BUILD_TYPE}")
  else()
    set(CMAKE_INSTALL_CONFIG_NAME "")
  endif()
  message(STATUS "Install configuration: \"${CMAKE_INSTALL_CONFIG_NAME}\"")
endif()

# Set the component getting installed.
if(NOT CMAKE_INSTALL_COMPONENT)
  if(COMPONENT)
    message(STATUS "Install component: \"${COMPONENT}\"")
    set(CMAKE_INSTALL_COMPONENT "${COMPONENT}")
  else()
    set(CMAKE_INSTALL_COMPONENT)
  endif()
endif()

# Install shared libraries without execute permission?
if(NOT DEFINED CMAKE_INSTALL_SO_NO_EXE)
  set(CMAKE_INSTALL_SO_NO_EXE "1")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/cpprest" TYPE FILE FILES
    "/src/app/find-object/dependencies/cpprestsdk/Release/include/cpprest/version.h"
    "/src/app/find-object/dependencies/cpprestsdk/Release/include/cpprest/base_uri.h"
    "/src/app/find-object/dependencies/cpprestsdk/Release/include/cpprest/http_headers.h"
    "/src/app/find-object/dependencies/cpprestsdk/Release/include/cpprest/rawptrstream.h"
    "/src/app/find-object/dependencies/cpprestsdk/Release/include/cpprest/filestream.h"
    "/src/app/find-object/dependencies/cpprestsdk/Release/include/cpprest/containerstream.h"
    "/src/app/find-object/dependencies/cpprestsdk/Release/include/cpprest/asyncrt_utils.h"
    "/src/app/find-object/dependencies/cpprestsdk/Release/include/cpprest/astreambuf.h"
    "/src/app/find-object/dependencies/cpprestsdk/Release/include/cpprest/interopstream.h"
    "/src/app/find-object/dependencies/cpprestsdk/Release/include/cpprest/json.h"
    "/src/app/find-object/dependencies/cpprestsdk/Release/include/cpprest/streams.h"
    "/src/app/find-object/dependencies/cpprestsdk/Release/include/cpprest/oauth1.h"
    "/src/app/find-object/dependencies/cpprestsdk/Release/include/cpprest/uri.h"
    "/src/app/find-object/dependencies/cpprestsdk/Release/include/cpprest/producerconsumerstream.h"
    "/src/app/find-object/dependencies/cpprestsdk/Release/include/cpprest/ws_client.h"
    "/src/app/find-object/dependencies/cpprestsdk/Release/include/cpprest/http_client.h"
    "/src/app/find-object/dependencies/cpprestsdk/Release/include/cpprest/http_listener.h"
    "/src/app/find-object/dependencies/cpprestsdk/Release/include/cpprest/ws_msg.h"
    "/src/app/find-object/dependencies/cpprestsdk/Release/include/cpprest/oauth2.h"
    "/src/app/find-object/dependencies/cpprestsdk/Release/include/cpprest/uri_builder.h"
    "/src/app/find-object/dependencies/cpprestsdk/Release/include/cpprest/http_msg.h"
    )
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/pplx" TYPE FILE FILES
    "/src/app/find-object/dependencies/cpprestsdk/Release/include/pplx/pplxwin.h"
    "/src/app/find-object/dependencies/cpprestsdk/Release/include/pplx/pplx.h"
    "/src/app/find-object/dependencies/cpprestsdk/Release/include/pplx/pplxcancellation_token.h"
    "/src/app/find-object/dependencies/cpprestsdk/Release/include/pplx/pplxinterface.h"
    "/src/app/find-object/dependencies/cpprestsdk/Release/include/pplx/pplxtasks.h"
    "/src/app/find-object/dependencies/cpprestsdk/Release/include/pplx/pplxlinux.h"
    "/src/app/find-object/dependencies/cpprestsdk/Release/include/pplx/threadpool.h"
    "/src/app/find-object/dependencies/cpprestsdk/Release/include/pplx/pplxconv.h"
    )
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/cpprest/details" TYPE FILE FILES
    "/src/app/find-object/dependencies/cpprestsdk/Release/include/cpprest/details/SafeInt3.hpp"
    "/src/app/find-object/dependencies/cpprestsdk/Release/include/cpprest/details/http_helpers.h"
    "/src/app/find-object/dependencies/cpprestsdk/Release/include/cpprest/details/http_client_impl.h"
    "/src/app/find-object/dependencies/cpprestsdk/Release/include/cpprest/details/nosal.h"
    "/src/app/find-object/dependencies/cpprestsdk/Release/include/cpprest/details/http_server.h"
    "/src/app/find-object/dependencies/cpprestsdk/Release/include/cpprest/details/basic_types.h"
    "/src/app/find-object/dependencies/cpprestsdk/Release/include/cpprest/details/uri_parser.h"
    "/src/app/find-object/dependencies/cpprestsdk/Release/include/cpprest/details/http_server_asio.h"
    "/src/app/find-object/dependencies/cpprestsdk/Release/include/cpprest/details/resource.h"
    "/src/app/find-object/dependencies/cpprestsdk/Release/include/cpprest/details/cpprest_compat.h"
    "/src/app/find-object/dependencies/cpprestsdk/Release/include/cpprest/details/http_server_api.h"
    "/src/app/find-object/dependencies/cpprestsdk/Release/include/cpprest/details/fileio.h"
    "/src/app/find-object/dependencies/cpprestsdk/Release/include/cpprest/details/x509_cert_utilities.h"
    "/src/app/find-object/dependencies/cpprestsdk/Release/include/cpprest/details/http_server_httpsys.h"
    "/src/app/find-object/dependencies/cpprestsdk/Release/include/cpprest/details/web_utilities.h"
    "/src/app/find-object/dependencies/cpprestsdk/Release/include/cpprest/details/http_constants.dat"
    )
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for each subdirectory.
  include("/src/app/find-object/dependencies/cpprestsdk/Release/src/cmake_install.cmake")
  include("/src/app/find-object/dependencies/cpprestsdk/Release/tests/cmake_install.cmake")
  include("/src/app/find-object/dependencies/cpprestsdk/Release/samples/cmake_install.cmake")

endif()

if(CMAKE_INSTALL_COMPONENT)
  set(CMAKE_INSTALL_MANIFEST "install_manifest_${CMAKE_INSTALL_COMPONENT}.txt")
else()
  set(CMAKE_INSTALL_MANIFEST "install_manifest.txt")
endif()

string(REPLACE ";" "\n" CMAKE_INSTALL_MANIFEST_CONTENT
       "${CMAKE_INSTALL_MANIFEST_FILES}")
file(WRITE "/src/app/find-object/dependencies/cpprestsdk/Release/${CMAKE_INSTALL_MANIFEST}"
     "${CMAKE_INSTALL_MANIFEST_CONTENT}")
