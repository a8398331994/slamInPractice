set (tag "1.22.10")

if(NOT EXISTS ${CMAKE_BINARY_DIR}/sophus)
    message(STATUS "Clone sophus repo")
    find_package(Git REQUIRED)
    execute_process(COMMAND ${GIT_EXECUTABLE} clone --depth 1 -v -b ${tag} -- https://github.com/strasdat/Sophus.git sophus
    WORKING_DIRECTORY ${CMAKE_BINARY_DIR}
    TIMEOUT 60
    RESULT_VARIABLE clone_result)

    if(NOT "${clone_result}" STREQUAL "0")
        message(FATAL_ERROR "Clone sophus repo failed")
    endif()
endif()

set(BUILD_SOPHUS_TESTS OFF)
set(BUILD_SOPHUS_EXAMPLES OFF)
add_subdirectory(${CMAKE_BINARY_DIR}/sophus ${CMAKE_BINARY_DIR}/sophus-build EXCLUDE_FROM_ALL)