#include <time.h>

#include "application.hpp"
#include "const.hpp"
#include "sdl.hpp"

// Set argc and argv as unused to remove compiler warnings
int main(int argc __attribute__((unused)), char* argv[] __attribute__((unused))) {
    SDL_Window* pWindow = SDL::createWindow("GodWorld");

#ifndef __APPLE__
    glewExperimental = GL_TRUE;
    glewInit();
#endif

    // Set clear color to dark blue
    glClearColor(0.0, 0.0, 0.2, 1.0);
    // Make sure depth is correctly rendered
    glEnable(GL_DEPTH_TEST);

    // set random seed
    srand(time(NULL));

    // Startup Application
    Application* pApplication = Application::createInstance(pWindow);
    pApplication->run();

    // Destroy Application
    SDL_DestroyWindow(pWindow);
    SDL_Quit();

    return 0;
}
