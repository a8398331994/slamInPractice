option(build_lie_algebra OFF)

if (${build_lie_algebra} STREQUAL ON OR ${build_all_project} STREQUAL ON)
    file(GLOB_RECURSE headers "${CMAKE_CURRENT_SOURCE_DIR}/include/*.h")
    file(GLOB_RECURSE sources "${CMAKE_CURRENT_SOURCE_DIR}/src/*.c*")

    project(LieAlgebra)
    find_package(Eigen3 REQUIRED)

    add_executable(LieAlgebra ${sources})

    target_include_directories(${PROJECT_NAME}
        PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/include)

    target_link_libraries(${PROJECT_NAME}
        PRIVATE Sophus::Sophus
    )

endif()