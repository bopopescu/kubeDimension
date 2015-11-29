# CMake generated Testfile for 
# Source directory: /src/app/find-object/dependencies/cpprestsdk/Release/tests/functional/streams
# Build directory: /src/app/find-object/dependencies/cpprestsdk/Release/tests/functional/streams
# 
# This file includes the relevant testing commands required for 
# testing this directory and lists subdirectories to be tested as well.
add_test(streams_test "/src/app/find-object/dependencies/cpprestsdk/Release/Binaries/test_runner" "libstreams_test.so")
set_tests_properties(streams_test PROPERTIES  WORKING_DIRECTORY "/src/app/find-object/dependencies/cpprestsdk/Release/Binaries")
