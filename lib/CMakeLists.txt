### UTIL LIBRARY ###
add_library(util "libutil/util/property.hpp")
target_include_directories(util PUBLIC libutil)
set_target_properties(util PROPERTIES LINKER_LANGUAGE CXX)


### GAME LIBRARY ###
set(ENGINE_SOURCES 
    "libengine/engine/guibinding/guibinding.cpp"
    "libengine/engine/models/ground.cpp"
    "libengine/engine/models/model.cpp"
    "libengine/engine/models/ray.cpp"
    "libengine/engine/models/settlement.cpp"
    "libengine/engine/models/sphere.cpp"
    "libengine/engine/models/square.cpp"
    "libengine/engine/noise/simplex_noise.cpp"
    "libengine/engine/objects/collider.cpp"
    "libengine/engine/objects/object.cpp"
    "libengine/engine/objects/planet.cpp"
    "libengine/engine/objects/sun.cpp"
    "libengine/engine/objects/transform.cpp"
    "libengine/engine/scene/scene.cpp"
    "libengine/engine/application.cpp"
    "libengine/engine/camera.cpp"
    "libengine/engine/color.cpp"
    "libengine/engine/sdl.cpp"
    "libengine/engine/shader.cpp"
    "libengine/engine/shadercontainer.cpp"
    "libengine/engine/util.cpp"
)

add_library(engine ${ENGINE_SOURCES})

target_include_directories(engine PUBLIC libengine/engine)
target_include_directories(engine PRIVATE "${GodWorld_SOURCE_DIR}/ext/imgui")

target_link_libraries(engine
    ${SDL2_LIBRARIES}
    ${OPENGL_LIBRARIES}
    ${GLEW_LIBRARIES}
    ${GLM_LIBRARIES}
    imgui
    util
)