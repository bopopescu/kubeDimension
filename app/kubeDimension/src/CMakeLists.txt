SET(headers_ui 
   ../include/${PROJECT_PREFIX}/FindObject.h
   ../include/${PROJECT_PREFIX}/Common.h
   ../include/${PROJECT_PREFIX}/Messages_reflection.h
   ../include/${PROJECT_PREFIX}/Messages_types.h
   ../include/${PROJECT_PREFIX}/Exif.h
   ../include/${PROJECT_PREFIX}/MainHandler.h
   ../include/${PROJECT_PREFIX}/TcpServer.h
   ../include/${PROJECT_PREFIX}/Worker.h
   ../include/${PROJECT_PREFIX}/HandlerFactory.h
   ../include/${PROJECT_PREFIX}/Eigen2CV.h
   ../include/${PROJECT_PREFIX}/JsonQt.h
   ../include/${PROJECT_PREFIX}/RedisQt.h
   ../include/hiredis/adapters/qt.h
)

QT4_WRAP_CPP(moc_srcs ${headers_ui})

SET(SRC_FILES 
   ../include/${PROJECT_PREFIX}/NanoFlann.hpp   
   ./JsonQt.cpp
   ./QtOpenCV.cpp
   ./Settings.cpp
   ./FindObject.cpp
   ./Vocabulary.cpp
   ./JsonWriter.cpp
   ./MainHandler.cpp
   ./TcpServer.cpp
   ./Worker.cpp
   ./HandlerFactory.cpp
   ./Exif.cpp
   ./utilite/ULogger.cpp
   ./utilite/UDirectory.cpp
   ./utilite/UFile.cpp
   ./utilite/UConversion.cpp
   ./json/jsoncpp.cpp
   ./Messages_types.cpp
   ./Messages.bond
   ${moc_srcs} 
   ${moc_uis} 
   ${srcs_qrc}
)

INCLUDE(${QT_USE_FILE})
find_package(Boost 1.5 REQUIRED COMPONENTS system filesystem)
find_package(Tufao REQUIRED)
#include_directories("${TUFAO_INCLUDE_DIR} ${INCLUDE_DIRS}")

find_package(TBB REQUIRED)
find_package(Eigen3 REQUIRED)
find_package(NanoMsg REQUIRED)
find_package(ZeroMQ REQUIRED)
find_package(HDF5 REQUIRED)
find_package(Redis REQUIRED)

INCLUDE(${QT_USE_FILE})
find_package(Boost 1.5 REQUIRED)

SET(INCLUDE_DIRS
        ${OpenCV_INCLUDE_DIRS}
        ${TBB_INCLUDE_DIRS}
        ${NANOMSG_INCLUDE_DIR}
        ${ZEROMQ_INCLUDE_DIRS}
        ${HDF5_INCLUDE_DIRS}
        ${HIREDIS_INCLUDE_DIR}
   ${CMAKE_CURRENT_SOURCE_DIR}/../include
   ${CMAKE_CURRENT_SOURCE_DIR}/../include/tbb
   ${CMAKE_CURRENT_SOURCE_DIR}/../include/nanomsg
   /usr/share/qt4/mkspecs/linux-g++-64/
   ${CMAKE_CURRENT_SOURCE_DIR}
   ${OpenCV_INCLUDE_DIRS}
   ${Boost_INCLUDE_DIRS}
   ${CMAKE_CURRENT_BINARY_DIR} # for qt ui generated in binary dir
)

SET(LIBRARIES
    ${QT_LIBRARIES}
    ${HIREDIS_LIBRARIES}
    ${OpenCV_LIBS}
    ${TBB_LIBRARIES}
    ${NANOMSG_LIBRARY}
    ${ZEROMQ_LIBRARIES}
    ${HDF5_LIBRARIES}
)

#SET(LIBRARIES
#   ${QT_LIBRARIES} 
#   ${OpenCV_LIBS} 
#  ${Boost_LIBRARIES}
#)

#include files
INCLUDE_DIRECTORIES(${INCLUDE_DIRS})

# create a library from the source files
ADD_LIBRARY(find_object ${SRC_FILES} ${Boost_LIBRARY_DIRS})

# Linking with Qt libraries
TARGET_LINK_LIBRARIES(find_object ${LIBRARIES})

   INSTALL(TARGETS find_object
      RUNTIME DESTINATION "${INSTALL_BIN_DIR}" COMPONENT runtime
      LIBRARY DESTINATION "${INSTALL_LIB_DIR}" COMPONENT devel
      ARCHIVE DESTINATION "${INSTALL_LIB_DIR}" COMPONENT devel)
      
   install(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/../include/ DESTINATION "${INSTALL_INCLUDE_DIR}" COMPONENT devel FILES_MATCHING PATTERN "*.h" PATTERN ".svn" EXCLUDE)
