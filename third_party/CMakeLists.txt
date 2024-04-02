cmake_minimum_required(VERSION 3.20)
include(FetchContent)
set(FETCHCONTENT_BASE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/src)

FetchContent_Declare(
    gperftools
    GIT_REPOSITORY https://github.com/gperftools/gperftools.git
    GIT_TAG master
)
# this can replace FetchContent_MakeAvailable and disable inner install by EXCLUDE_FROM_ALL
FetchContent_GetProperties(gperftools)
if(NOT gperftools_POPULATED)
  FetchContent_Populate(gperftools)
  set(BUILD_TESTING OFF CACHE BOOL "Disable all tests" FORCE)
  # Add the subdirectory containing gperftools, but exclude it from the all target
  add_subdirectory(${gperftools_SOURCE_DIR} ${gperftools_BINARY_DIR} EXCLUDE_FROM_ALL)
endif()

FetchContent_Declare(
    googletest
    GIT_REPOSITORY https://github.com/google/googletest.git
    GIT_TAG main
)
#set(INSTALL_GTEST OFF CACHE BOOL "" FORCE)
#FetchContent_MakeAvailable(googletest)
FetchContent_GetProperties(googletest)
if(NOT googletest_POPULATED)
  FetchContent_Populate(googletest)
  # Add the subdirectory containing gperftools, but exclude it from the all target
  add_subdirectory(${googletest_SOURCE_DIR} ${googletest_BINARY_DIR} EXCLUDE_FROM_ALL)
endif()
