find_package(Tufao 0.4 REQUIRED)
find_package(DLib REQUIRED)
find_package(TBB REQUIRED)
find_package(NanoMsg REQUIRED)
find_package(ZeroMQ REQUIRED)
  find_package(Crypto REQUIRED)
  find_package(OpenSSL 1.0.0 REQUIRED)
find_package(Boost 1.5 REQUIRED)
find_package(cpprest REQUIRED)
find_package(OpenCV 3 REQUIRED)
find_package( Threads REQUIRED)
#set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS}  -std=c++11 -std=c++1y -Wreorder -Wall -Wreorder")

SET(INCLUDE_DIRS
	${cpprest_LIB_DIR}
	${CMAKE_CURRENT_SOURCE_DIR}/../../include
        ${CMAKE_CURRENT_SOURCE_DIR}/../include
        ${CMAKE_CURRENT_SOURCE_DIR}
        ${TUFAO_LIBRARY}
        ${OpenCV_INCLUDE_DIRS}
        ${TBB_INCLUDE_DIRS}
        ${NANOMSG_INCLUDE_DIR}
        ${ZEROMQ_INCLUDE_DIRS}
)

INCLUDE(${QT_USE_FILE})

SET(LIBRARIES
    ${cpprest_LIBRARIES}
    ${QT_LIBRARIES}
    ${TUFAO_LIBRARIES}
    ${OpenCV_LIBS}
    ${TBB_LIBRARIES}
    ${NANOMSG_LIBRARY}
    ${ZEROMQ_LIBRARIES}
)

SET(headers_ui
        MainHandler.h
        PostHandler.h
        TcpResponse.h
        utils/exif.h
)

#This will generate moc_* for Qt
QT4_WRAP_CPP(moc_srcs ${headers_ui})

SET(SRC_FILES
        MainHandler.cpp
        PostHandler.cpp
        TcpResponse.cpp
        main.cpp
        utils/exif.cpp
       ${moc_srcs}
)

# Make sure the compiler can find include files from our library.
INCLUDE_DIRECTORIES(${INCLUDE_DIRS})

# Add binary called "example" that is built from the source file "main.cpp".
# The extension is automatically found.
ADD_EXECUTABLE(tcpRequest ${SRC_FILES})
TARGET_LINK_LIBRARIES(tcpRequest find_object ${SSL_LIB} ${CRYPTO_LIB}
	${LIBRARIES}
        ${cpprest_LIB_DIR}
        ${CPPREST_LIB}
    ${TUFAO_LIBRARY}
    ${QT_LIBRARIES}
    ${OpenCV_LIBS}
    ${TBB_LIBRARIES}
    ${NANOMSG_LIBRARY}
    ${ZEROMQ_LIBRARIES}
    ${Boost_LIBRARIES}
    ${Boost_FILESYSTEM_LIBRARY}
    ${Boost_THREAD_LIBRARY}
    ${Boost_SYSTEM_LIBRARY}
    ${Boost_REGEX_LIBRARY}
)

SET_TARGET_PROPERTIES( tcpRequest 
  PROPERTIES OUTPUT_NAME ${PROJECT_PREFIX}-tcpRequest)
  
INSTALL(TARGETS tcpRequest
        RUNTIME DESTINATION bin COMPONENT runtime
        BUNDLE DESTINATION "${CMAKE_BUNDLE_LOCATION}" COMPONENT runtime)

