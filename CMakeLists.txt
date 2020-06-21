cmake_minimum_required(VERSION 3.5)

project(GodWorld)

find_package(SDL2 REQUIRED)
find_package(OpenGL REQUIRED)
find_package(GLEW REQUIRED)
find_package(glm REQUIRED)

add_library(nanovg STATIC ${CMAKE_CURRENT_SOURCE_DIR}/ext/nanovg/src/nanovg.c)

include_directories(
    ${GLEW_INCLUDE_DIRS}
    ${GLM_INCLUDE_DIRS}
    ${CMAKE_CURRENT_SOURCE_DIR}/ext/nanovg/src
)

add_compile_options(
    -std=c++14
    -Wall
    -Wextra
    -D_GLIBCXX_DEBUG
)

add_subdirectory(lib)
add_subdirectory(apps)

set(CMAKE_EXPORT_COMPILE_COMMANDS 1)