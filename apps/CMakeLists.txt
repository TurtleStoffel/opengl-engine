set(godworldSources
    "godworld/scene/planetscene.cpp"
    "godworld/scene/systemscene.cpp"
    "godworld/gameapplication.cpp"
    "godworld/godworld.cpp"
)

set(modelviewerSources
    "modelviewer/scene/modelscene.cpp"
    "modelviewer/modelviewer.cpp"
    "modelviewer/modelviewerapplication.cpp"
)

add_executable(GodWorld ${godworldSources})
add_executable(ModelViewer ${modelviewerSources})

target_link_libraries(GodWorld
    engine
)

target_link_libraries(ModelViewer
    engine
)