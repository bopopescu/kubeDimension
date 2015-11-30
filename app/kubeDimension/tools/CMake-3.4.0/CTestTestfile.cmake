# CMake generated Testfile for 
# Source directory: /src/app/kubeDimension/tools/CMake-3.4.0
# Build directory: /src/app/kubeDimension/tools/CMake-3.4.0
# 
# This file includes the relevant testing commands required for 
# testing this directory and lists subdirectories to be tested as well.
include("/src/app/kubeDimension/tools/CMake-3.4.0/Tests/EnforceConfig.cmake")
add_test(SystemInformationNew "/src/app/kubeDimension/tools/CMake-3.4.0/bin/cmake" "--system-information" "-G" "Unix Makefiles")
subdirs(Utilities/KWIML)
subdirs(Source/kwsys)
subdirs(Utilities/cmzlib)
subdirs(Utilities/cmcurl)
subdirs(Utilities/cmcompress)
subdirs(Utilities/cmbzip2)
subdirs(Utilities/cmliblzma)
subdirs(Utilities/cmlibarchive)
subdirs(Utilities/cmexpat)
subdirs(Utilities/cmjsoncpp)
subdirs(Source)
subdirs(Utilities)
subdirs(Tests)
subdirs(Auxiliary)
