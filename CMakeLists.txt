cmake_minimum_required(VERSION 3.5)

project(GodWorld)

find_package(SDL2 REQUIRED)
find_package(OpenGL REQUIRED)
find_package(GLEW REQUIRED)
find_package(glm REQUIRED)

include_directories(
    ${GLEW_INCLUDE_DIRS}
    ${GLM_INCLUDE_DIRS}
)

set(CMAKE_CXX_STANDARD 17)

add_compile_options(
    -Wall
    -Wextra
    -D_GLIBCXX_DEBUG
)

set(IMGUI_DEMO_SOURCES
    "ext/imgui/examples/example_sdl_opengl3/main.cpp"
    "ext/imgui/examples/imgui_impl_opengl3.cpp"
    "ext/imgui/examples/imgui_impl_sdl.cpp"
    "ext/imgui/imgui_demo.cpp"
    "ext/imgui/imgui_draw.cpp"
    "ext/imgui/imgui_widgets.cpp"
    "ext/imgui/imgui.cpp"
)

add_library(imgui ${IMGUI_DEMO_SOURCES})

target_include_directories(imgui PRIVATE "ext/imgui")
target_include_directories(imgui PRIVATE "ext/imgui/examples")

target_link_libraries(imgui
    ${SDL2_LIBRARIES}
    ${OPENGL_LIBRARIES}
    ${GLEW_LIBRARIES}
)

add_subdirectory(lib)
add_subdirectory(apps)
add_subdirectory(ext/googletest)
add_subdirectory(test)

set(CMAKE_EXPORT_COMPILE_COMMANDS 1)