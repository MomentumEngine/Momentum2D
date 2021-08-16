cmake_minimum_required(VERSION 3.10)

set(CMAKE_CXX_STANDARD 20)

project(momentum LANGUAGES CXX)

option(GLFW_BUILD_DOCS OFF)
option(GLFW_BUILD_EXAMPLES OFF)
option(GLFW_BUILD_TESTS OFF)
option(BOX2D_BUILD_TESTBED "Build the Box2D testbed" OFF)

add_subdirectory(vendor/glad/)
add_subdirectory(vendor/glfw/)
#add_subdirectory(vendor/openal-soft/)
add_subdirectory(vendor/box2d/)
add_subdirectory(vendor/glm/)
add_subdirectory(vendor/spdlog/)

include_directories(vendor/glfw/include/
/include)

add_subdirectory(src/)

target_link_libraries(${PROJECT_NAME} glad glfw box2d glm spdlog)
