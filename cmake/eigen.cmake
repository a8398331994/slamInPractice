set(tag "3.4.0")

if(NOT EXISTS ${CMAKE_BINARY_DIR}/eigen)
    message(STATUS "Clone eigen repo")
    find_package(Git REQUIRED)
    execute_process(COMMAND ${GIT_EXECUTABLE} clone --depth 1 -v -b ${tag} -- https://gitlab.com/libeigen/eigen.git eigen
    WORKING_DIRECTORY ${CMAKE_BINARY_DIR}
    TIMEOUT 60
    RESULT_VARIABLE clone_result)

    if(NOT "${clone_result}" STREQUAL "0")
        message(FATAL_ERROR "Clone eigen repo failed")
    endif()
endif()

set(EIGEN_BUILD_DOC OFF)
set(BUILD_TESTING OFF)
add_subdirectory(${CMAKE_BINARY_DIR}/eigen ${CMAKE_BINARY_DIR}/eigen-build EXCLUDE_FROM_ALL)