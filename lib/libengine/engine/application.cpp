#include "application.hpp"

#include "engine/const.hpp"
#include "engine/scene.hpp"

#include "backends/imgui_impl_opengl3.h"
#include "backends/imgui_impl_sdl.h"
#include "imgui.h"

namespace Engine {
    Application::Application(SDL_Window* window)
          : m_window(window) {
        m_lastFpsTicks    = SDL_GetTicks();
        m_lastUpdateTicks = SDL_GetTicks();
    }

    auto Application::run() -> void {
        while (m_running) {
            ImGui_ImplOpenGL3_NewFrame();
            ImGui_ImplSDL2_NewFrame(m_window);
            ImGui::NewFrame();

            handleInput();
            updateScene();
            renderScene();
            throttleFps();
        }
    }

    auto Application::handleInput() -> void {
        SDL_Event event;
        while (SDL_PollEvent(&event)) {
            if (handleApplicationInput(event)) { // Application has handled the event
                continue;
            }
            if (m_scene->handleInput(event)) { // Scene is last thing to handle events
                continue;
            }
        }
    }

    auto Application::handleApplicationInput(SDL_Event event) -> bool {
        switch (event.type) {
            case SDL_WINDOWEVENT:
                if (event.window.event == SDL_WINDOWEVENT_RESIZED) {
                    auto windowWidth  = event.window.data1;
                    auto windowHeight = event.window.data2;
                    m_scene->setWindowSize(windowWidth, windowHeight);
                }
                return true;
            case SDL_QUIT:
                m_running = false;
                return true;
            case SDL_KEYDOWN:
                switch (event.key.keysym.sym) {
                    case SDLK_ESCAPE:
                        m_running = false;
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

    auto Application::updateScene() -> void {
        auto passedTicks = getTicksSinceLastUpdate();

        m_scene->update(passedTicks);
    }

    auto Application::renderScene() -> void {
        // Cleanup rendering buffers
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT | GL_STENCIL_BUFFER_BIT);

        m_scene->render();

        ImGui::Render();
        ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());

        SDL_GL_SwapWindow(m_window);
    }

    auto Application::throttleFps() -> void {
        auto currentFPSTick = SDL_GetTicks();
        if (currentFPSTick - m_lastFpsTicks < (1000 / constant::FPS)) {
            SDL_Delay(1000 / constant::FPS - currentFPSTick + m_lastFpsTicks);
        }
        m_lastFpsTicks = currentFPSTick;
    }

    auto Application::getTicksSinceLastUpdate() -> int {
        auto currentUpdateTicks = SDL_GetTicks();
        auto passedTicks        = currentUpdateTicks - m_lastUpdateTicks;
        m_lastUpdateTicks       = currentUpdateTicks;

        return passedTicks;
    }
}