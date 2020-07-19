set(TEST_SOURCES
    "libengine/engine/color_test.cpp"
    "libengine/engine/main.cpp"
)

add_executable(engine_test ${TEST_SOURCES})
add_test(NAME engine_test COMMAND engine_test)

target_link_libraries(engine_test
    engine
    gtest
)