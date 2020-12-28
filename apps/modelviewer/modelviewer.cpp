#include "modelviewerapplication.hpp"

#include "engine/sdl.hpp"

#include <time.h>

int main(int argc __attribute__((unused)), char* argv[] __attribute__((unused))) {
    SDL_Window* pWindow = SDL::createWindow("ModelViewer");

    // set random seed
    srand(time(NULL));

    // Startup Application
    Application* pApplication = new ModelViewerApplication(pWindow);
    pApplication->run();

    SDL::destroy(pWindow);

    return 0;
}