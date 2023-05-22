cmake_minimum_required(VERSION 3.20.0)

project(SlamInPractice)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_BINARY_DIR}/bin)

include(cmake/eigen.cmake)
include(cmake/sophus.cmake)

add_subdirectory(project)