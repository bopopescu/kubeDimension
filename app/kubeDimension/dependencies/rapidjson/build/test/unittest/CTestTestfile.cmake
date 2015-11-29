# CMake generated Testfile for 
# Source directory: /src/app/find-object/dependencies/rapidjson/test/unittest
# Build directory: /src/app/find-object/dependencies/rapidjson/build/test/unittest
# 
# This file includes the relevant testing commands required for 
# testing this directory and lists subdirectories to be tested as well.
add_test(unittest "/src/app/find-object/dependencies/rapidjson/build/bin/unittest")
set_tests_properties(unittest PROPERTIES  WORKING_DIRECTORY "/src/app/find-object/dependencies/rapidjson/bin")
add_test(valgrind_unittest "valgrind" "--leak-check=full" "--error-exitcode=1" "/src/app/find-object/dependencies/rapidjson/build/bin/unittest" "--gtest_filter=-SIMD.*")
set_tests_properties(valgrind_unittest PROPERTIES  WORKING_DIRECTORY "/src/app/find-object/dependencies/rapidjson/bin")
