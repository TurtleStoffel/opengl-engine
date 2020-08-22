#include "sdl.hpp"

#include "examples/imgui_impl_opengl3.h"
#include "examples/imgui_impl_sdl.h"
#include "imgui.h"

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

    SDL_GLContext glContext = SDL_GL_CreateContext(pWindow);

    IMGUI_CHECKVERSION();
    ImGui::CreateContext();
    ImGui::StyleColorsDark();

    ImGui_ImplSDL2_InitForOpenGL(pWindow, glContext);
    ImGui_ImplOpenGL3_Init("#version 330");

#ifndef __APPLE__
    glewExperimental = GL_TRUE;
    glewInit();
#endif

    // Set clear color to dark blue
    glClearColor(0.0, 0.0, 0.2, 1.0);

    glEnable(GL_DEPTH_TEST);

    // Enable transparent objects
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

    // Only render triangles that are facing towards the camera
    glEnable(GL_CULL_FACE);

    return pWindow;
}

void SDL::destroy(SDL_Window* pWindow) {
    SDL_DestroyWindow(pWindow);
    SDL_Quit();
}