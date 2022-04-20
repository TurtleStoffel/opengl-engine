#include "engine/sdl.hpp"

#include "engine/const.hpp"

#include "backends/imgui_impl_opengl3.h"
#include "backends/imgui_impl_sdl.h"
#include "imgui.h"

namespace Engine {
    auto SDL::createWindow(const std::string& name) -> SDL_Window* {
        SDL_LogSetAllPriority(SDL_LOG_PRIORITY_VERBOSE);

        SDL_Init(SDL_INIT_VIDEO);

        // Add SDL_WINDOW_FULLSCREEN_DESKTOP flag for Fullscreen at desktop resolution
        auto window = SDL_CreateWindow(name.c_str(),
                                       SDL_WINDOWPOS_CENTERED,
                                       SDL_WINDOWPOS_CENTERED,
                                       INITIAL_WINDOW_WIDTH,
                                       INITIAL_WINDOW_HEIGHT,
                                       SDL_WINDOW_OPENGL | SDL_WINDOW_BORDERLESS);

        // Generate OpenGL Context
        SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 3);
        SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 3);
        SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);

        // Enable Stencil Buffer for NanoVG
        SDL_GL_SetAttribute(SDL_GL_STENCIL_SIZE, 1);

        auto glContext = SDL_GL_CreateContext(window);

        IMGUI_CHECKVERSION();
        ImGui::CreateContext();
        ImGui::StyleColorsDark();

        ImGui_ImplSDL2_InitForOpenGL(window, glContext);
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

        glProvokingVertex(GL_FIRST_VERTEX_CONVENTION);

        // Only render triangles that are facing towards the camera
        glEnable(GL_CULL_FACE);

        return window;
    }

    auto SDL::destroy(SDL_Window* window) -> void {
        SDL_DestroyWindow(window);
        SDL_Quit();
    }
}