#include "sdl.hpp"

#include "const.hpp"

SDL_Window* SDL::createWindow(const std::string name) {
    SDL_Init(SDL_INIT_VIDEO);

    // Add SDL_WINDOW_FULLSCREEN_DESKTOP flag for Fullscreen at desktop resolution
    SDL_Window* pWindow = SDL_CreateWindow(name.c_str(),
                                           SDL_WINDOWPOS_CENTERED,
                                           SDL_WINDOWPOS_CENTERED,
                                           constant::initialWindowWidth,
                                           constant::initialWindowHeight,
                                           SDL_WINDOW_OPENGL | SDL_WINDOW_BORDERLESS);

    // Generate OpenGL Context
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 3);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 3);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);

    // Enable Stencil Buffer for NanoVG
    SDL_GL_SetAttribute(SDL_GL_STENCIL_SIZE, 1);

    SDL_GL_CreateContext(pWindow);

    return pWindow;
}