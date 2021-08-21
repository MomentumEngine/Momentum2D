cmake_minimum_required(VERSION 3.7...3.20)

if(${CMAKE_VERSION} VERSION_LESS 3.12)
    cmake_policy(VERSION ${CMAKE_MAJOR_VERSION}.${CMAKE_MINOR_VERSION})
endif()


set(CMAKE_CXX_STANDARD 20)

project(momentum LANGUAGES CXX)

option(GLFW_BUILD_DOCS OFF)
option(GLFW_BUILD_EXAMPLES OFF)
option(GLFW_BUILD_TESTS OFF)
option(BOX2D_BUILD_TESTBED "Build the Box2D testbed" OFF)

if(CMAKE_COMPILER_IS_GNUCXX)
add_compile_options(-Wall -Wextra -Wpedantic -O3 -fsanitize=address -fsanitize=undefined)
add_link_options(-Wall -Wextra -Wpedantic -O3 -fsanitize=address -fsanitize=undefined)
endif(CMAKE_COMPILER_IS_GNUCXX)

add_subdirectory(vendor/glad/)
add_subdirectory(vendor/glfw/)
add_subdirectory(vendor/openal-soft/)
add_subdirectory(vendor/box2d/)
add_subdirectory(vendor/glm/)
add_subdirectory(vendor/spdlog/)

add_subdirectory(src/)

include_directories(vendor/glfw/include/
/include)


target_link_libraries(${PROJECT_NAME} glad glfw box2d glm spdlog OpenAL)
