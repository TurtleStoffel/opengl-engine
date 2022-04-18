set(sources
    "src/scene/systemscene.cpp"
    "src/gameapplication.cpp"
    "src/godworld.cpp"
)

add_executable(GodWorld ${sources})

target_link_libraries(GodWorld
    engine
)