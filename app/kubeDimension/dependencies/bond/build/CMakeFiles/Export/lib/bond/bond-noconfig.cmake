#----------------------------------------------------------------
# Generated CMake target import file.
#----------------------------------------------------------------

# Commands may need to know the format version.
set(CMAKE_IMPORT_FILE_VERSION 1)

# Import target "bond" for configuration ""
set_property(TARGET bond APPEND PROPERTY IMPORTED_CONFIGURATIONS NOCONFIG)
set_target_properties(bond PROPERTIES
  IMPORTED_LINK_INTERFACE_LANGUAGES_NOCONFIG "CXX"
  IMPORTED_LOCATION_NOCONFIG "${_IMPORT_PREFIX}/lib/bond/libbond.a"
  )

list(APPEND _IMPORT_CHECK_TARGETS bond )
list(APPEND _IMPORT_CHECK_FILES_FOR_bond "${_IMPORT_PREFIX}/lib/bond/libbond.a" )

# Import target "bond_apply" for configuration ""
set_property(TARGET bond_apply APPEND PROPERTY IMPORTED_CONFIGURATIONS NOCONFIG)
set_target_properties(bond_apply PROPERTIES
  IMPORTED_LINK_INTERFACE_LANGUAGES_NOCONFIG "CXX"
  IMPORTED_LOCATION_NOCONFIG "${_IMPORT_PREFIX}/lib/bond/libbond_apply.a"
  )

list(APPEND _IMPORT_CHECK_TARGETS bond_apply )
list(APPEND _IMPORT_CHECK_FILES_FOR_bond_apply "${_IMPORT_PREFIX}/lib/bond/libbond_apply.a" )

# Commands beyond this point should not need to know the version.
set(CMAKE_IMPORT_FILE_VERSION)
