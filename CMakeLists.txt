cmake_minimum_required(VERSION 3.10)

project(momentum LANGUAGES CXX)

option(GLFW_BUILD_DOCS OFF)
option(GLFW_BUILD_EXAMPLES OFF)
option(GLFW_BUILD_TESTS OFF)

add_subdirectory(vendor/glfw/)
add_subdirectory(vendor/glad/)

include_directories(vendor/glfw/include/
                    include/)

add_executable(${PROJECT_NAME} src/main.cpp)

target_link_libraries(${PROJECT_NAME} glad glfw)