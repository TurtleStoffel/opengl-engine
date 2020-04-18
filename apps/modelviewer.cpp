#include "sdl.hpp"

int main(int argc __attribute__((unused)), char* argv[] __attribute__((unused))) {
    SDL_Window* pWindow = SDL::createWindow("ModelViewer");

#ifndef __APPLE__
    glewExperimental = GL_TRUE;
    glewInit();
#endif

    // Set clear color to dark blue
    glClearColor(0.0, 0.0, 0.2, 1.0);
    // Make sure depth is correctly rendered
    glEnable(GL_DEPTH_TEST);

    // Destroy Application
    SDL_DestroyWindow(pWindow);
    SDL_Quit();

    return 0;
}