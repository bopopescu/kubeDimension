# CMake generated Testfile for 
# Source directory: /src/app/kubeDimension/include/cpp-netlib-0.11.2-final/libs/network/test
# Build directory: /src/app/kubeDimension/include/cpp-netlib-0.11.2-final/libs/network/test
# 
# This file includes the relevant testing commands required for 
# testing this directory and lists subdirectories to be tested as well.
add_test(cpp-netlib-message_test "/src/app/kubeDimension/include/cpp-netlib-0.11.2-final/tests/cpp-netlib-message_test")
add_test(cpp-netlib-message_transform_test "/src/app/kubeDimension/include/cpp-netlib-0.11.2-final/tests/cpp-netlib-message_transform_test")
add_test(cpp-netlib-utils_thread_pool "/src/app/kubeDimension/include/cpp-netlib-0.11.2-final/tests/cpp-netlib-utils_thread_pool")
subdirs(uri)
subdirs(http)
