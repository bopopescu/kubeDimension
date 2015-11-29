# CMake generated Testfile for 
# Source directory: /src/app/find-object/dependencies/bond/python/test/core
# Build directory: /src/app/find-object/dependencies/bond/build/python/test/core
# 
# This file includes the relevant testing commands required for 
# testing this directory and lists subdirectories to be tested as well.
add_test(python_unit_test "/usr/bin/cmake" "-DPYTHON_EXECUTABLE=/usr/bin/python2.7" "-DPYTHONPATH=/src/app/find-object/dependencies/bond/build/python/test/core" "-DSCRIPT=/src/app/find-object/dependencies/bond/python/test/core/unit_test.py" "-P" "/src/app/find-object/dependencies/bond/cmake/RunPythonTest.cmake")
set_tests_properties(python_unit_test PROPERTIES  WORKING_DIRECTORY "/src/app/find-object/dependencies/bond/build/python/test/core")
