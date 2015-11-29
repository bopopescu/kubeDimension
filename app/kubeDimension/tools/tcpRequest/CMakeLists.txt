find_package(Tufao REQUIRED)
find_package(DLib REQUIRED)
find_package(TBB REQUIRED)
find_package(NanoMsg REQUIRED)
find_package(ZeroMQ REQUIRED)

find_package(Boost 1.36.0)

set(Boost_USE_STATIC_LIBS        ON) # only find static libs
set(Boost_USE_MULTITHREADED      ON)
find_package(Boost REQUIRED)
find_package(Boost COMPONENTS regex date_time system filesystem thread graph)

#set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS}  -std=c++11 -std=c++1y -Wreorder -Wall -Wreorder")

SET(headers_ui 
	MainHandler.h
	PostHandler.h
	TcpResponse.h
	utils/exif.h
)

#This will generate moc_* for Qt
QT4_WRAP_CPP(moc_srcs ${headers_ui})

include_directories(${BOOST_INCLUDE_DIRS})

SET(SRC_FILES
	MainHandler.cpp    
	PostHandler.cpp
    	TcpResponse.cpp
    	main.cpp
	utils/exif.cpp    
       ${moc_srcs} 
)

SET(INCLUDE_DIRS
	${CMAKE_CURRENT_SOURCE_DIR}/../../include
        ${CMAKE_CURRENT_SOURCE_DIR}/../include
        ${CMAKE_CURRENT_SOURCE_DIR}
	/usr/local/include/Tufao/
        ${TUFAO_LIBRARY}
        ${OpenCV_INCLUDE_DIRS}
        ${TBB_INCLUDE_DIRS}
        ${NANOMSG_INCLUDE_DIR}
        ${ZEROMQ_INCLUDE_DIRS}
)

INCLUDE(${QT_USE_FILE})

SET(LIBRARIES
    ${QT_LIBRARIES}
    ${TUFAO_LIBRARIES}
    ${OpenCV_LIBS}
    ${TBB_LIBRARIES}
    ${NANOMSG_LIBRARY}
    ${ZEROMQ_LIBRARIES}
)

# Make sure the compiler can find include files from our library.
INCLUDE_DIRECTORIES(${INCLUDE_DIRS})

# Add binary called "example" that is built from the source file "main.cpp".
# The extension is automatically found.
ADD_EXECUTABLE(tcpRequest ${SRC_FILES})
TARGET_LINK_LIBRARIES(tcpRequest find_object ${LIBRARIES} ${Boost_LIBRARIES}
    ${Boost_FILESYSTEM_LIBRARY}
    ${TUFAO_LIBRARY}
    ${QT_LIBRARIES}
    ${TUFAO_LIBRARY}
    ${OpenCV_LIBS}
    ${TBB_LIBRARIES}
    ${NANOMSG_LIBRARY}
    ${ZEROMQ_LIBRARIES}
    ${Boost_THREAD_LIBRARY}
    ${Boost_SYSTEM_LIBRARY}
    ${TUFA0_LIBRARIES})

SET_TARGET_PROPERTIES( tcpRequest 
  PROPERTIES OUTPUT_NAME ${PROJECT_PREFIX}-tcpRequest)
  
INSTALL(TARGETS tcpRequest
        RUNTIME DESTINATION bin COMPONENT runtime
        BUNDLE DESTINATION "${CMAKE_BUNDLE_LOCATION}" COMPONENT runtime)

