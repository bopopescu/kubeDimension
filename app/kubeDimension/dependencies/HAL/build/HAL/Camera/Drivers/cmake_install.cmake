# Install script for directory: /src/app/find-object/dependencies/HAL/HAL/Camera/Drivers

# Set the install prefix
if(NOT DEFINED CMAKE_INSTALL_PREFIX)
  set(CMAKE_INSTALL_PREFIX "/usr/local")
endif()
string(REGEX REPLACE "/$" "" CMAKE_INSTALL_PREFIX "${CMAKE_INSTALL_PREFIX}")

# Set the install configuration name.
if(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)
  if(BUILD_TYPE)
    string(REGEX REPLACE "^[^A-Za-z0-9_]+" ""
           CMAKE_INSTALL_CONFIG_NAME "${BUILD_TYPE}")
  else()
    set(CMAKE_INSTALL_CONFIG_NAME "")
  endif()
  message(STATUS "Install configuration: \"${CMAKE_INSTALL_CONFIG_NAME}\"")
endif()

# Set the component getting installed.
if(NOT CMAKE_INSTALL_COMPONENT)
  if(COMPONENT)
    message(STATUS "Install component: \"${COMPONENT}\"")
    set(CMAKE_INSTALL_COMPONENT "${COMPONENT}")
  else()
    set(CMAKE_INSTALL_COMPONENT)
  endif()
endif()

# Install shared libraries without execute permission?
if(NOT DEFINED CMAKE_INSTALL_SO_NO_EXE)
  set(CMAKE_INSTALL_SO_NO_EXE "1")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for each subdirectory.
  include("/src/app/find-object/dependencies/HAL/build/HAL/Camera/Drivers/ROS/cmake_install.cmake")
  include("/src/app/find-object/dependencies/HAL/build/HAL/Camera/Drivers/NodeCam/cmake_install.cmake")
  include("/src/app/find-object/dependencies/HAL/build/HAL/Camera/Drivers/Split/cmake_install.cmake")
  include("/src/app/find-object/dependencies/HAL/build/HAL/Camera/Drivers/ProtoReader/cmake_install.cmake")
  include("/src/app/find-object/dependencies/HAL/build/HAL/Camera/Drivers/Undistort/cmake_install.cmake")
  include("/src/app/find-object/dependencies/HAL/build/HAL/Camera/Drivers/Ximea/cmake_install.cmake")
  include("/src/app/find-object/dependencies/HAL/build/HAL/Camera/Drivers/AutoExposure/cmake_install.cmake")
  include("/src/app/find-object/dependencies/HAL/build/HAL/Camera/Drivers/OpenCV/cmake_install.cmake")
  include("/src/app/find-object/dependencies/HAL/build/HAL/Camera/Drivers/Debayer/cmake_install.cmake")
  include("/src/app/find-object/dependencies/HAL/build/HAL/Camera/Drivers/Flycap/cmake_install.cmake")
  include("/src/app/find-object/dependencies/HAL/build/HAL/Camera/Drivers/V4L/cmake_install.cmake")
  include("/src/app/find-object/dependencies/HAL/build/HAL/Camera/Drivers/Android/cmake_install.cmake")
  include("/src/app/find-object/dependencies/HAL/build/HAL/Camera/Drivers/Cleave/cmake_install.cmake")
  include("/src/app/find-object/dependencies/HAL/build/HAL/Camera/Drivers/FireFly/cmake_install.cmake")
  include("/src/app/find-object/dependencies/HAL/build/HAL/Camera/Drivers/UVC/cmake_install.cmake")
  include("/src/app/find-object/dependencies/HAL/build/HAL/Camera/Drivers/AlliedVision/cmake_install.cmake")
  include("/src/app/find-object/dependencies/HAL/build/HAL/Camera/Drivers/DC1394/cmake_install.cmake")
  include("/src/app/find-object/dependencies/HAL/build/HAL/Camera/Drivers/Rectify/cmake_install.cmake")
  include("/src/app/find-object/dependencies/HAL/build/HAL/Camera/Drivers/FileReader/cmake_install.cmake")
  include("/src/app/find-object/dependencies/HAL/build/HAL/Camera/Drivers/Deinterlace/cmake_install.cmake")
  include("/src/app/find-object/dependencies/HAL/build/HAL/Camera/Drivers/Freenect2/cmake_install.cmake")
  include("/src/app/find-object/dependencies/HAL/build/HAL/Camera/Drivers/Epiphan/cmake_install.cmake")
  include("/src/app/find-object/dependencies/HAL/build/HAL/Camera/Drivers/Join/cmake_install.cmake")
  include("/src/app/find-object/dependencies/HAL/build/HAL/Camera/Drivers/NodeSimCam/cmake_install.cmake")
  include("/src/app/find-object/dependencies/HAL/build/HAL/Camera/Drivers/OpenNI/cmake_install.cmake")
  include("/src/app/find-object/dependencies/HAL/build/HAL/Camera/Drivers/Convert/cmake_install.cmake")
  include("/src/app/find-object/dependencies/HAL/build/HAL/Camera/Drivers/ToyotaReader/cmake_install.cmake")
  include("/src/app/find-object/dependencies/HAL/build/HAL/Camera/Drivers/SimCam/cmake_install.cmake")
  include("/src/app/find-object/dependencies/HAL/build/HAL/Camera/Drivers/Occam/cmake_install.cmake")
  include("/src/app/find-object/dependencies/HAL/build/HAL/Camera/Drivers/KitKat/cmake_install.cmake")
  include("/src/app/find-object/dependencies/HAL/build/HAL/Camera/Drivers/RealSense/cmake_install.cmake")
  include("/src/app/find-object/dependencies/HAL/build/HAL/Camera/Drivers/OpenNI2/cmake_install.cmake")
  include("/src/app/find-object/dependencies/HAL/build/HAL/Camera/Drivers/HDMI/cmake_install.cmake")

endif()

