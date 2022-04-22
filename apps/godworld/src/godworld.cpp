#include "engine/sdl.hpp"
#include "gameapplication.hpp"

int main() {
    Engine::SDL::startApplication<Godworld::GameApplication>("GodWorld");
    return 0;
}
