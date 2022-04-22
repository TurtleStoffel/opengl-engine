#include "application.hpp"

#include "engine/sdl.hpp"

int main() {
    Engine::SDL::startApplication<ModelEditor::Application>("ModelEditor");
    return 0;
}