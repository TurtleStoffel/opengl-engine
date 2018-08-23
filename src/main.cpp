#include "application.hpp"

#include "const.hpp"

int main(int argc __attribute__((unused)), char* argv[] __attribute__((unused))) {
    // Init SDL and create window
    SDL_Init(SDL_INIT_VIDEO);
    SDL_Window* pWindow = SDL_CreateWindow("GodWorld",
                                           SDL_WINDOWPOS_CENTERED,
                                           SDL_WINDOWPOS_CENTERED,
                                           constant::initialWindowWidth,
                                           constant::initialWindowHeight,
                                           SDL_WINDOW_OPENGL | SDL_WINDOW_RESIZABLE);

    // Generate OpenGL Context
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 3);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 3);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);
    SDL_GLContext context __attribute__((unused)) = SDL_GL_CreateContext(pWindow);

#ifndef __APPLE__
    glewExperimental = GL_TRUE;
    glewInit();
#endif

    // Set clear color to dark blue
    glClearColor(0.0, 0.0, 0.2, 1.0);
    // Make sure depth is correctly rendered
    glEnable(GL_DEPTH_TEST);

    // Startup Application
    Application application = Application(pWindow);
    application.run();

    // Destroy Application
    SDL_DestroyWindow(pWindow);
    SDL_Quit();

    return 0;
}
