################################################################################
# Sophus source dir
set( Sophus_SOURCE_DIR "/src/app/find-object/dependencies/Sophus")

################################################################################
# Sophus build dir
set( Sophus_DIR "/src/app/find-object/dependencies/Sophus/build")

################################################################################
# Compute paths
get_filename_component(Sophus_CMAKE_DIR "${CMAKE_CURRENT_LIST_FILE}" PATH)

set( Sophus_INCLUDE_DIR  "/src/app/find-object/dependencies/Sophus;/usr/include/eigen3" )
set( Sophus_INCLUDE_DIRS  "/src/app/find-object/dependencies/Sophus;/usr/include/eigen3" )
