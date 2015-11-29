# CMake generated Testfile for 
# Source directory: /src/app/find-object/dependencies/cpprestsdk/Release/tests/functional/websockets/client
# Build directory: /src/app/find-object/dependencies/cpprestsdk/Release/tests/functional/websockets/client
# 
# This file includes the relevant testing commands required for 
# testing this directory and lists subdirectories to be tested as well.
add_test(websocketclient_test "/src/app/find-object/dependencies/cpprestsdk/Release/Binaries/test_runner" "libwebsocketclient_test.so")
set_tests_properties(websocketclient_test PROPERTIES  WORKING_DIRECTORY "/src/app/find-object/dependencies/cpprestsdk/Release/Binaries")
