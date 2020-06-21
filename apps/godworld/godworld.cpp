#include <time.h>

#include "gameapplication.hpp"
#include "sdl.hpp"

// Set argc and argv as unused to remove compiler warnings
int main(int argc __attribute__((unused)), char* argv[] __attribute__((unused))) {
    SDL_Window* pWindow = SDL::createWindow("GodWorld");

    // set random seed
    srand(time(NULL));

    Application* pApplication = new GameApplication(pWindow);
    pApplication->run();

    SDL::destroy(pWindow);

    return 0;
}
