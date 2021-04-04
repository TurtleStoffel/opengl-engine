#include "application.hpp"

#include "backends/imgui_impl_opengl3.h"
#include "backends/imgui_impl_sdl.h"
#include "imgui.h"

#include "engine/const.hpp"
#include "engine/scene/scene.hpp"
#include "engine/shaders/shaderregistry.hpp"

Application::Application(SDL_Window* window)
      : window(window) {
    _lastFpsTicks    = SDL_GetTicks();
    _lastUpdateTicks = SDL_GetTicks();
}

void Application::run() {
    _createScene();

    while (_running) {
        ImGui_ImplOpenGL3_NewFrame();
        ImGui_ImplSDL2_NewFrame(window);
        ImGui::NewFrame();

        _handleInput();
        _updateScene();
        _renderScene();
        _throttleFps();
    }
}

void Application::_handleInput() {
    SDL_Event event;
    while (SDL_PollEvent(&event)) {
        if (_handleApplicationInput(event)) { // Application has handled the event
            continue;
        }
        if (m_scene->handleInput(event)) { // Scene is last thing to handle events
            continue;
        }
    }
}

bool Application::_handleApplicationInput(SDL_Event event) {
    switch (event.type) {
        case SDL_WINDOWEVENT:
            if (event.window.event == SDL_WINDOWEVENT_RESIZED) {
                int windowWidth  = event.window.data1;
                int windowHeight = event.window.data2;
                m_scene->setWindowSize(windowWidth, windowHeight);
            }
            return true;
        case SDL_QUIT:
            _running = false;
            return true;
        case SDL_KEYDOWN:
            switch (event.key.keysym.sym) {
                case SDLK_ESCAPE:
                    _running = false;
                    return true;
                case SDLK_z:
                    glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
                    return true;
                case SDLK_x:
                    glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
                    return true;
            }
    }
    return false;
}

void Application::_updateScene() {
    int passedTicks = _getTicksSinceLastUpdate();

    m_scene->update(passedTicks);
}

void Application::_renderScene() {
    // Cleanup rendering buffers
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT | GL_STENCIL_BUFFER_BIT);

    m_scene->render();

    ImGui::Render();
    ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());

    SDL_GL_SwapWindow(window);
}

void Application::_throttleFps() {
    int currentFPSTick = SDL_GetTicks();
    if (currentFPSTick - _lastFpsTicks < (1000 / constant::FPS)) {
        SDL_Delay(1000 / constant::FPS - currentFPSTick + _lastFpsTicks);
    }
    _lastFpsTicks = currentFPSTick;
}

int Application::_getTicksSinceLastUpdate() {
    int currentUpdateTicks = SDL_GetTicks();
    int passedTicks        = currentUpdateTicks - _lastUpdateTicks;
    _lastUpdateTicks       = currentUpdateTicks;

    return passedTicks;
}