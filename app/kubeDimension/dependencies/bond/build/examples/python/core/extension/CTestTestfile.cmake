# CMake generated Testfile for 
# Source directory: /src/app/find-object/dependencies/bond/examples/python/core/extension
# Build directory: /src/app/find-object/dependencies/bond/build/examples/python/core/extension
# 
# This file includes the relevant testing commands required for 
# testing this directory and lists subdirectories to be tested as well.
add_test(python_extension "/usr/bin/cmake" "-DPYTHON_EXECUTABLE=/usr/bin/python2.7" "-DPYTHONPATH=/src/app/find-object/dependencies/bond/build/examples/python/core/extension" "-DSCRIPT=/src/app/find-object/dependencies/bond/examples/python/core/extension/example.py" "-P" "/src/app/find-object/dependencies/bond/cmake/RunPythonTest.cmake")
set_tests_properties(python_extension PROPERTIES  WORKING_DIRECTORY "/src/app/find-object/dependencies/bond/build/examples/python/core/extension")
