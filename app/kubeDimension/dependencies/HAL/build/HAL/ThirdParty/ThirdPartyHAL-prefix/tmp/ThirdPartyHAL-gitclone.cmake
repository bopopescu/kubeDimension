if("master" STREQUAL "")
  message(FATAL_ERROR "Tag for git checkout should not be empty.")
endif()

set(run 0)

if("/src/app/find-object/dependencies/HAL/build/HAL/ThirdParty/ThirdPartyHAL-prefix/src/ThirdPartyHAL-stamp/ThirdPartyHAL-gitinfo.txt" IS_NEWER_THAN "/src/app/find-object/dependencies/HAL/build/HAL/ThirdParty/ThirdPartyHAL-prefix/src/ThirdPartyHAL-stamp/ThirdPartyHAL-gitclone-lastrun.txt")
  set(run 1)
endif()

if(NOT run)
  message(STATUS "Avoiding repeated git clone, stamp file is up to date: '/src/app/find-object/dependencies/HAL/build/HAL/ThirdParty/ThirdPartyHAL-prefix/src/ThirdPartyHAL-stamp/ThirdPartyHAL-gitclone-lastrun.txt'")
  return()
endif()

execute_process(
  COMMAND ${CMAKE_COMMAND} -E remove_directory "/src/app/find-object/dependencies/HAL/build/HAL/ThirdParty/ThirdPartyHAL-prefix/src/ThirdPartyHAL"
  RESULT_VARIABLE error_code
  )
if(error_code)
  message(FATAL_ERROR "Failed to remove directory: '/src/app/find-object/dependencies/HAL/build/HAL/ThirdParty/ThirdPartyHAL-prefix/src/ThirdPartyHAL'")
endif()

# try the clone 3 times incase there is an odd git clone issue
set(error_code 1)
set(number_of_tries 0)
while(error_code AND number_of_tries LESS 3)
  execute_process(
    COMMAND "/usr/bin/git" clone "arpg@arpg-web.colorado.edu:git/ThirdPartyHAL" "ThirdPartyHAL"
    WORKING_DIRECTORY "/src/app/find-object/dependencies/HAL/build/HAL/ThirdParty/ThirdPartyHAL-prefix/src"
    RESULT_VARIABLE error_code
    )
  math(EXPR number_of_tries "${number_of_tries} + 1")
endwhile()
if(number_of_tries GREATER 1)
  message(STATUS "Had to git clone more than once:
          ${number_of_tries} times.")
endif()
if(error_code)
  message(FATAL_ERROR "Failed to clone repository: 'arpg@arpg-web.colorado.edu:git/ThirdPartyHAL'")
endif()

execute_process(
  COMMAND "/usr/bin/git" checkout master
  WORKING_DIRECTORY "/src/app/find-object/dependencies/HAL/build/HAL/ThirdParty/ThirdPartyHAL-prefix/src/ThirdPartyHAL"
  RESULT_VARIABLE error_code
  )
if(error_code)
  message(FATAL_ERROR "Failed to checkout tag: 'master'")
endif()

execute_process(
  COMMAND "/usr/bin/git" submodule init 
  WORKING_DIRECTORY "/src/app/find-object/dependencies/HAL/build/HAL/ThirdParty/ThirdPartyHAL-prefix/src/ThirdPartyHAL"
  RESULT_VARIABLE error_code
  )
if(error_code)
  message(FATAL_ERROR "Failed to init submodules in: '/src/app/find-object/dependencies/HAL/build/HAL/ThirdParty/ThirdPartyHAL-prefix/src/ThirdPartyHAL'")
endif()

execute_process(
  COMMAND "/usr/bin/git" submodule update --recursive 
  WORKING_DIRECTORY "/src/app/find-object/dependencies/HAL/build/HAL/ThirdParty/ThirdPartyHAL-prefix/src/ThirdPartyHAL"
  RESULT_VARIABLE error_code
  )
if(error_code)
  message(FATAL_ERROR "Failed to update submodules in: '/src/app/find-object/dependencies/HAL/build/HAL/ThirdParty/ThirdPartyHAL-prefix/src/ThirdPartyHAL'")
endif()

# Complete success, update the script-last-run stamp file:
#
execute_process(
  COMMAND ${CMAKE_COMMAND} -E copy
    "/src/app/find-object/dependencies/HAL/build/HAL/ThirdParty/ThirdPartyHAL-prefix/src/ThirdPartyHAL-stamp/ThirdPartyHAL-gitinfo.txt"
    "/src/app/find-object/dependencies/HAL/build/HAL/ThirdParty/ThirdPartyHAL-prefix/src/ThirdPartyHAL-stamp/ThirdPartyHAL-gitclone-lastrun.txt"
  WORKING_DIRECTORY "/src/app/find-object/dependencies/HAL/build/HAL/ThirdParty/ThirdPartyHAL-prefix/src/ThirdPartyHAL"
  RESULT_VARIABLE error_code
  )
if(error_code)
  message(FATAL_ERROR "Failed to copy script-last-run stamp file: '/src/app/find-object/dependencies/HAL/build/HAL/ThirdParty/ThirdPartyHAL-prefix/src/ThirdPartyHAL-stamp/ThirdPartyHAL-gitclone-lastrun.txt'")
endif()

