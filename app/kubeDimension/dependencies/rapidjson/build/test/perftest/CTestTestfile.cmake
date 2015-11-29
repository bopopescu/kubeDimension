# CMake generated Testfile for 
# Source directory: /src/app/find-object/dependencies/rapidjson/test/perftest
# Build directory: /src/app/find-object/dependencies/rapidjson/build/test/perftest
# 
# This file includes the relevant testing commands required for 
# testing this directory and lists subdirectories to be tested as well.
add_test(perftest "/src/app/find-object/dependencies/rapidjson/build/bin/perftest")
set_tests_properties(perftest PROPERTIES  WORKING_DIRECTORY "/src/app/find-object/dependencies/rapidjson/bin")
