cmake_minimum_required(VERSION 3.22.0)

project(SlamInPractice)

option(build_all_project "Flag to build all project" OFF)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_BINARY_DIR}/bin)

# include thirdparty cmake file
include(cmake/eigen.cmake)
include(cmake/sophus.cmake)

add_subdirectory(project)