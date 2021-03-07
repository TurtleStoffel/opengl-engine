set(ENGINE_SOURCES 
    "libengine/engine/guibinding/gui_factory.cpp"
    "libengine/engine/guibinding/planet_gui.cpp"
    "libengine/engine/guibinding/sun_configuration_gui.cpp"
    "libengine/engine/guibinding/sun_gui.cpp"
    "libengine/engine/models/effects/debug_vectors.cpp"
    "libengine/engine/models/effects/glow.cpp"
    "libengine/engine/models/effects/outline.cpp"
    "libengine/engine/models/model.cpp"
    "libengine/engine/models/rectangle_model.cpp"
    "libengine/engine/models/sphere.cpp"
    "libengine/engine/models/vector.cpp"
    "libengine/engine/noise/simplex_noise.cpp"
    "libengine/engine/objects/collider.cpp"
    "libengine/engine/objects/object.cpp"
    "libengine/engine/objects/planet.cpp"
    "libengine/engine/objects/rectangle.cpp"
    "libengine/engine/objects/sun.cpp"
    "libengine/engine/objects/transform.cpp"
    "libengine/engine/scene/scene.cpp"
    "libengine/engine/shaders/circleshader.cpp"
    "libengine/engine/shaders/glowshader.cpp"
    "libengine/engine/shaders/lowpolyshader.cpp"
    "libengine/engine/shaders/shader.cpp"
    "libengine/engine/shaders/shadercontainer.cpp"
    "libengine/engine/shaders/silhouetteshader.cpp"
    "libengine/engine/application.cpp"
    "libengine/engine/camera.cpp"
    "libengine/engine/color.cpp"
    "libengine/engine/sdl.cpp"
    "libengine/engine/util.cpp"
)

add_library(engine ${ENGINE_SOURCES})

target_include_directories(engine PUBLIC libengine)
target_include_directories(engine PUBLIC "${GodWorld_SOURCE_DIR}/ext/imgui")

target_link_libraries(engine
    ${SDL2_LIBRARIES}
    ${OPENGL_LIBRARIES}
    ${GLEW_LIBRARIES}
    ${GLM_LIBRARIES}
    imgui
)