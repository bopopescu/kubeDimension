ADD_DEFINITIONS(
    #-std=c++11 # Or -std=c++0x
    # Other flags
    -pthread -fdiagnostics-color=auto -fmax-errors=1 -std=c++14 -O2 -g -fno-omit-frame-pointer -fno-inline
    -DBOND_COMPACT_BINARY_PROTOCOL
    -lssl -lcrypto
)

set(Boost_USE_MULTITHREADED ON)  
find_package(Tufao 0.4 REQUIRED)
find_package(TBB REQUIRED)
find_package(Eigen3 REQUIRED)
find_package(NanoMsg REQUIRED)
find_package(ZeroMQ REQUIRED)
find_package(HDF5 REQUIRED)
find_package(Redis REQUIRED)
find_package(cpprest REQUIRED)
  find_package(Crypto REQUIRED)
  find_package(OpenSSL 1.0.0 REQUIRED)
INCLUDE(${QT_USE_FILE})
SET(INCLUDE_DIRS
        ${CMAKE_CURRENT_SOURCE_DIR}/../include
        ${CMAKE_CURRENT_SOURCE_DIR}
	${cpprest_LIB_DIR}
        ${OpenCV_INCLUDE_DIRS}
        ${TUFAO_INCLUDE_DIR}
	${TBB_INCLUDE_DIRS}
	${Boost_LIBRARY_DIRS}
        ${NANOMSG_INCLUDE_DIR}
        ${ZEROMQ_INCLUDE_DIRS}
	${HDF5_INCLUDE_DIRS}
	${HIREDIS_INCLUDE_DIR}
)

SET(LIBRARIES
    ${QT_LIBRARIES} 
    ${TUFAO_LIBRARIES}
    ${HIREDIS_LIBRARIES}
    ${OpenCV_LIBS} 
    ${TBB_LIBRARIES}
    ${NANOMSG_LIBRARY}
    ${ZEROMQ_LIBRARIES}
    ${HDF5_LIBRARIES}
    ${Boost_LIBRARIES}
    ${cpprest_LIBRARIES}
)

#set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -std=c++1y -Wreorder ")

#include files
INCLUDE_DIRECTORIES(${INCLUDE_DIRS})

SET(SRC_FILES main.cpp)

# create an executable file
IF(APPLE AND BUILD_AS_BUNDLE)
  ADD_EXECUTABLE(find_object_app MACOSX_BUNDLE ${SRC_FILES})
ELSEIF(MINGW)
  ADD_EXECUTABLE(find_object_app WIN32 ${SRC_FILES})
ELSE()
  ADD_EXECUTABLE(find_object_app ${SRC_FILES})
ENDIF()

# Linking with Qt libraries
TARGET_LINK_LIBRARIES(find_object_app find_object ${SSL_LIB} ${CRYPTO_LIB}  ${LIBRARIES} 
    ${OPENSSL_LIBRARIES}
    ${QT_LIBRARIES}
    ${TUFAO_LIBRARIES}
    ${HIREDIS_LIBRARIES}
    ${OpenCV_LIBS}
    ${TBB_LIBRARIES}
    ${Boost_FILESYSTEM_LIBRARY}
    ${Boost_THREAD_LIBRARY}
    ${Boost_SYSTEM_LIBRARY}
    ${NANOMSG_LIBRARY}
    ${ZEROMQ_LIBRARIES}
    ${Boost_LIBRARIES}
    ${HDF5_LIBRARIES} )

IF(APPLE AND BUILD_AS_BUNDLE)
  SET_TARGET_PROPERTIES(find_object_app PROPERTIES
    OUTPUT_NAME ${CMAKE_BUNDLE_NAME})
ELSEIF(WIN32)
  SET_TARGET_PROPERTIES(find_object_app PROPERTIES
    OUTPUT_NAME ${PROJECT_NAME})
ELSE()
  SET_TARGET_PROPERTIES(find_object_app PROPERTIES
    OUTPUT_NAME ${PROJECT_PREFIX})
ENDIF()

#---------------------------
# Installation stuff
#--------------------------- 

#TARGET_LINK_LIBRARIES(find_object_app find_object ${LIBRARIES} ${Boost_LIBRARIES}
#    ${Boost_FILESYSTEM_LIBRARY}
#    ${TUFAO_LIBRARY}
#    ${Boost_THREAD_LIBRARY}
#    ${Boost_SYSTEM_LIBRARY}
#    ${TUFA0_LIBRARIES}
#)

INSTALL(TARGETS find_object_app
        RUNTIME DESTINATION "${INSTALL_BIN_DIR}" COMPONENT runtime
        BUNDLE DESTINATION "${CMAKE_BUNDLE_LOCATION}" COMPONENT runtime)
        
#---------------------------
# Dependencies packaging
#---------------------------
IF(APPLE AND BUILD_AS_BUNDLE)
  INSTALL(CODE "execute_process(COMMAND ln -s \"../MacOS/${CMAKE_BUNDLE_NAME}\" ${PROJECT_NAME}
        WORKING_DIRECTORY \$ENV{DESTDIR}\${CMAKE_INSTALL_PREFIX}/bin)")
ENDIF(APPLE AND BUILD_AS_BUNDLE)

IF((APPLE AND BUILD_AS_BUNDLE) OR WIN32)
  SET(APPS "\$ENV{DESTDIR}\${CMAKE_INSTALL_PREFIX}/bin/${PROJECT_NAME}${CMAKE_EXECUTABLE_SUFFIX}")
  SET(plugin_dest_dir bin)
  SET(qtconf_dest_dir bin)
  IF(APPLE)
    SET(plugin_dest_dir MacOS)
    SET(qtconf_dest_dir Resources)
    SET(APPS "\$ENV{DESTDIR}\${CMAKE_INSTALL_PREFIX}/MacOS/${CMAKE_BUNDLE_NAME}")
  ENDIF(APPLE)
  
  # Install needed Qt plugins by copying directories from the qt installation
  # One can cull what gets copied by using 'REGEX "..." EXCLUDE'
  # Exclude debug libraries
  INSTALL(DIRECTORY "${QT_PLUGINS_DIR}/imageformats" 
          DESTINATION ${plugin_dest_dir}/plugins 
          COMPONENT runtime 
          REGEX ".*d4.dll" EXCLUDE
          REGEX ".*d4.a" EXCLUDE)
  
  # install a qt.conf file
  # this inserts some cmake code into the install script to write the file
  SET(QT_CONF_FILE [Paths]\nPlugins=plugins)
  IF(APPLE)
    SET(QT_CONF_FILE [Paths]\nPlugins=MacOS/plugins)
  ENDIF(APPLE)
  INSTALL(CODE "
    file(WRITE \"\$ENV{DESTDIR}\${CMAKE_INSTALL_PREFIX}/${qtconf_dest_dir}/qt.conf\" \"${QT_CONF_FILE}\")
    " COMPONENT runtime)

  # directories to look for dependencies
  SET(DIRS ${QT_LIBRARY_DIRS} ${PROJECT_SOURCE_DIR}/bin)
  IF(APPLE)
    SET(DIRS ${DIRS} /usr/local /usr/local/lib)
  ENDIF(APPLE)

  # Now the work of copying dependencies into the bundle/package
  # The quotes are escaped and variables to use at install time have their $ escaped
  # An alternative is the do a configure_file() on a script and use install(SCRIPT  ...).
  # Note that the image plugins depend on QtSvg and QtXml, and it got those copied
  # over.
  # To find dependencies, cmake use "otool" on Apple and "dumpbin" on Windows (make sure you have one of them).
  install(CODE "
   file(GLOB_RECURSE QTPLUGINS \"\$ENV{DESTDIR}\${CMAKE_INSTALL_PREFIX}/${plugin_dest_dir}/plugins/*${CMAKE_SHARED_LIBRARY_SUFFIX}\")
    include(\"BundleUtilities\")
    fixup_bundle(\"${APPS}\" \"\${QTPLUGINS}\" \"${DIRS}\")
  " COMPONENT runtime)
ENDIF((APPLE AND BUILD_AS_BUNDLE) OR WIN32)

