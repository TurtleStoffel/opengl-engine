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
    "libengine/engine/components/collider.cpp"
    "libengine/engine/components/color_selector.cpp"
    "libengine/engine/components/component.cpp"
    "libengine/engine/components/effect.cpp"
    "libengine/engine/components/model.cpp"
    "libengine/engine/components/shader.cpp"
    "libengine/engine/components/transform.cpp"
    "libengine/engine/entities/background.cpp"
    "libengine/engine/entities/entity.cpp"
    "libengine/engine/entities/planet.cpp"
    "libengine/engine/entities/star.cpp"
    "libengine/engine/noise/simplex_noise.cpp"
    "libengine/engine/shaders/glow.cpp"
    "libengine/engine/shaders/lowpoly.cpp"
    "libengine/engine/shaders/registry.cpp"
    "libengine/engine/shaders/shader.cpp"
    "libengine/engine/shaders/silhouette.cpp"
    "libengine/engine/system/rendering.cpp"
    "libengine/engine/application.cpp"
    "libengine/engine/camera.cpp"
    "libengine/engine/color.cpp"
    "libengine/engine/scene.cpp"
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