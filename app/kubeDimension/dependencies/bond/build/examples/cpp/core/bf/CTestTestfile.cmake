# CMake generated Testfile for 
# Source directory: /src/app/find-object/dependencies/bond/examples/cpp/core/bf
# Build directory: /src/app/find-object/dependencies/bond/build/examples/cpp/core/bf
# 
# This file includes the relevant testing commands required for 
# testing this directory and lists subdirectories to be tested as well.
add_test(bf "/usr/bin/cmake" "-DBF=/src/app/find-object/dependencies/bond/build/examples/cpp/core/bf/bf" "-DBOND_COMPAT=/src/app/find-object/dependencies/bond/build/cpp/test/compat/compatibility_test" "-DCOMPAT_DATA=/src/app/find-object/dependencies/bond/test/compat/data" "-P" "/src/app/find-object/dependencies/bond/examples/cpp/core/bf/bf_test.cmake")
set_tests_properties(bf PROPERTIES  WORKING_DIRECTORY "/src/app/find-object/dependencies/bond/build/examples/cpp/core/bf")
add_test(bf_schema "/src/app/find-object/dependencies/bond/build/examples/cpp/core/bf/bf" "/src/app/find-object/dependencies/bond/test/compat/data/compat.schema.dat")
set_tests_properties(bf_schema PROPERTIES  WORKING_DIRECTORY "/src/app/find-object/dependencies/bond/build/examples/cpp/core/bf")
