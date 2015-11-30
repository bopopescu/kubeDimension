# CMake generated Testfile for 
# Source directory: /src/app/kubeDimension/include/HyperTable/htbuild-dir/cmake-2.6.4
# Build directory: /src/app/kubeDimension/include/HyperTable/htbuild-dir/cmake-2.6.4
# 
# This file replicates the SUBDIRS() and ADD_TEST() commands from the source
# tree CMakeLists.txt file, skipping any SUBDIRS() or ADD_TEST() commands
# that are excluded by CMake control structures, i.e. IF() commands.
ADD_TEST(SystemInformationNew "/src/app/kubeDimension/include/HyperTable/htbuild-dir/cmake-2.6.4/bin/cmake" "--system-information" "-G" "Unix Makefiles")
SUBDIRS(Source/kwsys)
SUBDIRS(Utilities/cmzlib)
SUBDIRS(Utilities/cmcurl)
SUBDIRS(Utilities/cmtar)
SUBDIRS(Utilities/cmcompress)
SUBDIRS(Utilities/cmexpat)
SUBDIRS(Utilities/cmxmlrpc)
SUBDIRS(Source)
SUBDIRS(Modules)
SUBDIRS(Templates)
SUBDIRS(Utilities)
SUBDIRS(Tests)
