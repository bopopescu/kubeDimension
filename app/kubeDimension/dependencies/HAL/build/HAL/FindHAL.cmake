
SET( HAL_LIBRARIES  /usr/local/lib/libopencv_core.so.3.0.0;/usr/local/lib/libopencv_imgproc.so.3.0.0;/usr/local/lib/libopencv_imgcodecs.so.3.0.0;/usr/local/lib/libopencv_videoio.so.3.0.0;/usr/lib/x86_64-linux-gnu/libdc1394.so;/usr/lib/x86_64-linux-gnu/libraw1394.so;/usr/lib/x86_64-linux-gnu/libtinyxml2.so;/usr/lib/x86_64-linux-gnu/libprotobuf.so;-lpthread;/usr/local/lib/libglog.so;hal CACHE INTERNAL "HAL libraries" FORCE )
SET( HAL_INCLUDE_DIRS  /usr/include/eigen3;/usr/local/lib/cmake/Sophus/../../../include;/usr/include CACHE INTERNAL "HAL include directories" FORCE )
SET( HAL_LIBRARY_DIRS  CACHE INTERNAL "HAL library directories" FORCE )

mark_as_advanced( HAL_LIBRARIES )
mark_as_advanced( HAL_LIBRARY_DIRS )
mark_as_advanced( HAL_INCLUDE_DIRS )


