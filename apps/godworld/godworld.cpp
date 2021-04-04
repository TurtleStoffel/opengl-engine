#include "engine/sdl.hpp"
#include "gameapplication.hpp"

#include <memory>
#include <time.h>

int main() {
    SDL_Window* window = SDL::createWindow("GodWorld");

    // set random seed
    srand(time(NULL));

    std::unique_ptr<Application> application = std::make_unique<Godworld::GameApplication>(window);
    application->run();

    SDL::destroy(window);

    return 0;
}
