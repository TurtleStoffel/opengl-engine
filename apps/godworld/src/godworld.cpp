#include "engine/sdl.hpp"
#include "gameapplication.hpp"

#include <memory>
#include <time.h>

int main() {
    auto window = Engine::SDL::createWindow("GodWorld");

    // set random seed
    srand(time(NULL));

    auto application = std::make_unique<Godworld::GameApplication>(*window);
    application->run();

    Engine::SDL::destroy(window);

    return 0;
}
