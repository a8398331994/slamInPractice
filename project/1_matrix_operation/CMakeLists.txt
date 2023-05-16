option(build_matrix_operation OFF)

file(GLOB_RECURSE headers "${CMAKE_CURRENT_SOURCE_DIR}/include/*.h")
file(GLOB_RECURSE sources "${CMAKE_CURRENT_SOURCE_DIR}/src/*.c*")

project(MatrixOperation)
find_package(Eigen3)

add_executable(MatrixOperation ${sources})

target_include_directories(${PROJECT_NAME}
    PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/include)

target_link_libraries(${PROJECT_NAME}
    PRIVATE Eigen3::Eigen
)