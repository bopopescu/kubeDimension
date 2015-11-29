# Install script for directory: /src/app/find-object/dependencies/bond/examples/cpp/core

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
  include("/src/app/find-object/dependencies/bond/build/examples/cpp/core/access_control/cmake_install.cmake")
  include("/src/app/find-object/dependencies/bond/build/examples/cpp/core/attributes/cmake_install.cmake")
  include("/src/app/find-object/dependencies/bond/build/examples/cpp/core/bf/cmake_install.cmake")
  include("/src/app/find-object/dependencies/bond/build/examples/cpp/core/compile_time_schema/cmake_install.cmake")
  include("/src/app/find-object/dependencies/bond/build/examples/cpp/core/container_of_pointers/cmake_install.cmake")
  include("/src/app/find-object/dependencies/bond/build/examples/cpp/core/enumerations/cmake_install.cmake")
  include("/src/app/find-object/dependencies/bond/build/examples/cpp/core/generic_tree/cmake_install.cmake")
  include("/src/app/find-object/dependencies/bond/build/examples/cpp/core/generics/cmake_install.cmake")
  include("/src/app/find-object/dependencies/bond/build/examples/cpp/core/import/cmake_install.cmake")
  include("/src/app/find-object/dependencies/bond/build/examples/cpp/core/inheritance/cmake_install.cmake")
  include("/src/app/find-object/dependencies/bond/build/examples/cpp/core/marshaling/cmake_install.cmake")
  include("/src/app/find-object/dependencies/bond/build/examples/cpp/core/merge/cmake_install.cmake")
  include("/src/app/find-object/dependencies/bond/build/examples/cpp/core/modifying_transform/cmake_install.cmake")
  include("/src/app/find-object/dependencies/bond/build/examples/cpp/core/move_semantics/cmake_install.cmake")
  include("/src/app/find-object/dependencies/bond/build/examples/cpp/core/multiprecision/cmake_install.cmake")
  include("/src/app/find-object/dependencies/bond/build/examples/cpp/core/nothing_default/cmake_install.cmake")
  include("/src/app/find-object/dependencies/bond/build/examples/cpp/core/output_stream_allocator/cmake_install.cmake")
  include("/src/app/find-object/dependencies/bond/build/examples/cpp/core/polymorphic_container/cmake_install.cmake")
  include("/src/app/find-object/dependencies/bond/build/examples/cpp/core/polymorphic_container_visitor/cmake_install.cmake")
  include("/src/app/find-object/dependencies/bond/build/examples/cpp/core/protocol_transcoding/cmake_install.cmake")
  include("/src/app/find-object/dependencies/bond/build/examples/cpp/core/protocol_versions/cmake_install.cmake")
  include("/src/app/find-object/dependencies/bond/build/examples/cpp/core/record_streaming/cmake_install.cmake")
  include("/src/app/find-object/dependencies/bond/build/examples/cpp/core/runtime_binding/cmake_install.cmake")
  include("/src/app/find-object/dependencies/bond/build/examples/cpp/core/runtime_schema/cmake_install.cmake")
  include("/src/app/find-object/dependencies/bond/build/examples/cpp/core/schema_view/cmake_install.cmake")
  include("/src/app/find-object/dependencies/bond/build/examples/cpp/core/serialization/cmake_install.cmake")
  include("/src/app/find-object/dependencies/bond/build/examples/cpp/core/simple_json/cmake_install.cmake")
  include("/src/app/find-object/dependencies/bond/build/examples/cpp/core/static_array/cmake_install.cmake")
  include("/src/app/find-object/dependencies/bond/build/examples/cpp/core/static_library/cmake_install.cmake")
  include("/src/app/find-object/dependencies/bond/build/examples/cpp/core/string_ref/cmake_install.cmake")
  include("/src/app/find-object/dependencies/bond/build/examples/cpp/core/time_alias/cmake_install.cmake")
  include("/src/app/find-object/dependencies/bond/build/examples/cpp/core/trace/cmake_install.cmake")
  include("/src/app/find-object/dependencies/bond/build/examples/cpp/core/transform/cmake_install.cmake")
  include("/src/app/find-object/dependencies/bond/build/examples/cpp/core/variadic/cmake_install.cmake")

endif()

