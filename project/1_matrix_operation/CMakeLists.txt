option(build_matrix_operation OFF)

if (${build_matrix_operation} STREQUAL ON OR ${build_all_project} STREQUAL ON)
    file(GLOB_RECURSE headers "${CMAKE_CURRENT_SOURCE_DIR}/include/*.h")
    file(GLOB_RECURSE sources "${CMAKE_CURRENT_SOURCE_DIR}/src/*.c*")

    project(MatrixOperation)
    find_package(Eigen3 REQUIRED)

    add_executable(MatrixOperation ${sources})

    target_include_directories(${PROJECT_NAME}
        PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/include)

    target_link_libraries(${PROJECT_NAME}
        PRIVATE Eigen3::Eigen
    )
endif()