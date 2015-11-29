# CMake generated Testfile for 
# Source directory: /src/app/find-object/dependencies/cpprestsdk/Release/tests/functional/json
# Build directory: /src/app/find-object/dependencies/cpprestsdk/Release/tests/functional/json
# 
# This file includes the relevant testing commands required for 
# testing this directory and lists subdirectories to be tested as well.
add_test(json_test "/src/app/find-object/dependencies/cpprestsdk/Release/Binaries/test_runner" "libjson_test.so")
set_tests_properties(json_test PROPERTIES  WORKING_DIRECTORY "/src/app/find-object/dependencies/cpprestsdk/Release/Binaries")
