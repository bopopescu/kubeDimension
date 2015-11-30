# CMake generated Testfile for 
# Source directory: /src/app/kubeDimension/tools/CMake-3.4.0/Utilities/cmcurl
# Build directory: /src/app/kubeDimension/tools/CMake-3.4.0/Utilities/cmcurl
# 
# This file includes the relevant testing commands required for 
# testing this directory and lists subdirectories to be tested as well.
add_test(curl "LIBCURL" "http://open.cdash.org/user.php")
subdirs(lib)
