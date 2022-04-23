set(modelEditorSources
    "src/entities/triangle.cpp"
    "src/models/triangle.cpp"
    "src/scene/scene.cpp"
    "src/application.cpp"
    "src/model_editor.cpp"
)

add_executable(ModelEditor ${modelEditorSources})

target_include_directories(ModelEditor PUBLIC src)

target_link_libraries(ModelEditor
    engine
)