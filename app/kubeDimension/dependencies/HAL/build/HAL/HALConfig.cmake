SET( HAL_LIBRARIES  "/usr/local/lib/libopencv_core.so.3.0.0;/usr/local/lib/libopencv_imgproc.so.3.0.0;/usr/local/lib/libopencv_imgcodecs.so.3.0.0;/usr/local/lib/libopencv_videoio.so.3.0.0;/usr/lib/x86_64-linux-gnu/libdc1394.so;/usr/lib/x86_64-linux-gnu/libraw1394.so;/usr/lib/x86_64-linux-gnu/libtinyxml2.so;/usr/lib/x86_64-linux-gnu/libprotobuf.so;-lpthread;/usr/local/lib/libglog.so;hal" CACHE INTERNAL "HAL libraries" FORCE )
SET( HAL_INCLUDE_DIRS  /usr/include/eigen3;/usr/local/lib/cmake/Sophus/../../../include;/usr/include CACHE INTERNAL "HAL include directories" FORCE )
SET( HAL_LIBRARY_DIRS  CACHE INTERNAL "HAL library directories" FORCE )

mark_as_advanced( HAL_LIBRARIES )
mark_as_advanced( HAL_LIBRARY_DIRS )
mark_as_advanced( HAL_INCLUDE_DIRS )



# Compute paths
get_filename_component( PACKAGE_CMAKE_DIR "${CMAKE_CURRENT_LIST_FILE}" PATH )

# This file, when used for INSTALLED code, does not use Targets... sigh.
## Library dependencies (contains definitions for IMPORTED targets)
#if(NOT TARGET "HAL_LIBRARIES" AND NOT "HAL_BINARY_DIR")
#    include( "${PACKAGE_CMAKE_DIR}/HALTargets.cmake" )
#    include( "${PACKAGE_CMAKE_DIR}/HALConfigVersion.cmake" )
#endif()

#SET(HAL_LIBRARIES )
#SET(HAL_LIBRARY )
#SET(HAL_INCLUDE_DIRS /usr/include/eigen3;/usr/local/lib/cmake/Sophus/../../../include;/usr/include)
#SET(HAL_LINK_DIRS )
