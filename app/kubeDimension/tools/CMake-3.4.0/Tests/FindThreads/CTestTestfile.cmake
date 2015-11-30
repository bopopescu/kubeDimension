# CMake generated Testfile for 
# Source directory: /src/app/kubeDimension/tools/CMake-3.4.0/Tests/FindThreads
# Build directory: /src/app/kubeDimension/tools/CMake-3.4.0/Tests/FindThreads
# 
# This file includes the relevant testing commands required for 
# testing this directory and lists subdirectories to be tested as well.
add_test(FindThreads.C-only "/src/app/kubeDimension/tools/CMake-3.4.0/bin/ctest" "--build-and-test" "/src/app/kubeDimension/tools/CMake-3.4.0/Tests/FindThreads/C-only" "/src/app/kubeDimension/tools/CMake-3.4.0/Tests/FindThreads/C-only" "--build-generator" "Unix Makefiles" "--build-project" "FindThreads_C-only" "--build-options" "-DCMAKE_MAKE_PROGRAM:FILEPATH=/usr/bin/make" "--test-command" "/src/app/kubeDimension/tools/CMake-3.4.0/bin/ctest" "-V")
add_test(FindThreads.CXX-only "/src/app/kubeDimension/tools/CMake-3.4.0/bin/ctest" "--build-and-test" "/src/app/kubeDimension/tools/CMake-3.4.0/Tests/FindThreads/CXX-only" "/src/app/kubeDimension/tools/CMake-3.4.0/Tests/FindThreads/CXX-only" "--build-generator" "Unix Makefiles" "--build-project" "FindThreads_CXX-only" "--build-options" "-DCMAKE_MAKE_PROGRAM:FILEPATH=/usr/bin/make" "--test-command" "/src/app/kubeDimension/tools/CMake-3.4.0/bin/ctest" "-V")
