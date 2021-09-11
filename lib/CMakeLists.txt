set(ENGINE_SOURCES 
    "libengine/engine/components/effects/debug_vectors.cpp"
    "libengine/engine/components/effects/glow.cpp"
    "libengine/engine/components/effects/outline.cpp"
    "libengine/engine/components/gui/component_gui.cpp"
    "libengine/engine/components/gui/composite_gui.cpp"
    "libengine/engine/components/gui/planet_gui.cpp"
    "libengine/engine/components/gui/star_configuration_gui.cpp"
    "libengine/engine/components/gui/star_gui.cpp"
    "libengine/engine/components/models/background_model.cpp"
    "libengine/engine/components/models/sphere.cpp"
    "libengine/engine/components/models/vector.cpp"
    "libengine/engine/components/scripts/demo_rotation.cpp"
    "libengine/engine/components/scripts/planet_rotation.cpp"
    "libengine/engine/components/shaders/generic_shader_component.cpp"
    "libengine/engine/components/collider.cpp"
    "libengine/engine/components/color_selector.cpp"
    "libengine/engine/components/component.cpp"
    "libengine/engine/components/effect.cpp"
    "libengine/engine/components/model.cpp"
    "libengine/engine/components/transform.cpp"
    "libengine/engine/noise/simplex_noise.cpp"
    "libengine/engine/objects/background.cpp"
    "libengine/engine/objects/entity.cpp"
    "libengine/engine/objects/planet.cpp"
    "libengine/engine/objects/star.cpp"
    "libengine/engine/scene/scene.cpp"
    "libengine/engine/shaders/circleshader.cpp"
    "libengine/engine/shaders/glowshader.cpp"
    "libengine/engine/shaders/lowpolyshader.cpp"
    "libengine/engine/shaders/shader.cpp"
    "libengine/engine/shaders/shaderregistry.cpp"
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