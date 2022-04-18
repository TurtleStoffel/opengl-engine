set(modelviewerSources
    "src/scene/modelscene.cpp"
    "src/modelviewer.cpp"
    "src/modelviewerapplication.cpp"
)

add_executable(ModelViewer ${modelviewerSources})

target_link_libraries(ModelViewer
    engine
)