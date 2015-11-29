# CMake generated Testfile for 
# Source directory: /src/app/find-object/dependencies/bond/python/test/compat
# Build directory: /src/app/find-object/dependencies/bond/build/python/test/compat
# 
# This file includes the relevant testing commands required for 
# testing this directory and lists subdirectories to be tested as well.
add_test(python_compatibility_compact "/usr/bin/cmake" "-DPYTHON_EXECUTABLE=/usr/bin/python2.7" "-DPYTHON_COMPAT=/src/app/find-object/dependencies/bond/build/python/test/compat" "-DBOND_COMPAT=/src/app/find-object/dependencies/bond/build/cpp/test/compat/compatibility_test" "-DCOMPAT_DATA=/src/app/find-object/dependencies/bond/test/compat/data" "-DTEST=compact" "-DSOURCE_DIR=/src/app/find-object/dependencies/bond/python/test/compat" "-P" "/src/app/find-object/dependencies/bond/python/test/compat/compat.cmake")
set_tests_properties(python_compatibility_compact PROPERTIES  WORKING_DIRECTORY "/src/app/find-object/dependencies/bond/build/python/test/compat")
add_test(python_compatibility_schema "/usr/bin/cmake" "-DPYTHON_EXECUTABLE=/usr/bin/python2.7" "-DPYTHON_COMPAT=/src/app/find-object/dependencies/bond/build/python/test/compat" "-DBOND_COMPAT=/src/app/find-object/dependencies/bond/build/cpp/test/compat/compatibility_test" "-DCOMPAT_DATA=/src/app/find-object/dependencies/bond/test/compat/data" "-DTEST=schema" "-DSOURCE_DIR=/src/app/find-object/dependencies/bond/python/test/compat" "-P" "/src/app/find-object/dependencies/bond/python/test/compat/compat.cmake")
set_tests_properties(python_compatibility_schema PROPERTIES  WORKING_DIRECTORY "/src/app/find-object/dependencies/bond/build/python/test/compat")
