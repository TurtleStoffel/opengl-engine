#include "application.hpp"

#include "examples/imgui_impl_opengl3.h"
#include "examples/imgui_impl_sdl.h"
#include "imgui.h"

#include "camera.hpp"
#include "const.hpp"
#include "shader.hpp"
#include "shadercontainer.hpp"

Application* Application::_pApplication = nullptr;

Application::Application(SDL_Window* pWindow) {
    // Only one instance of this class should ever be created, otherwise throw error
    assert(!_pApplication);

    _pApplication = this;
    _pWindow      = pWindow;
}

Application::~Application() {
}

Application* Application::instance() {
    // Check that an instance of the Application already exists
    assert(_pApplication);

    return _pApplication;
}

void Application::run() {
    _setupApplication();

    while (_running) {
        ImGui_ImplOpenGL3_NewFrame();
        ImGui_ImplSDL2_NewFrame(_pWindow);
        ImGui::NewFrame();

        _handleInput();
        _updateScene();
        _renderScene();
        _throttleFps();
    }
}

Camera* Application::getCamera() {
    assert(_pCamera);

    return _pCamera.get();
}

Scene* Application::getScene() {
    assert(_pScene);

    return _pScene.get();
}

void Application::_setupApplication() {
    // Initialize all shaders
    ShaderContainer::init();

    _pCamera = std::make_unique<Camera>();

    _createScene();

    _lastFpsTicks    = SDL_GetTicks();
    _lastUpdateTicks = SDL_GetTicks();
}

void Application::_handleInput() {
    SDL_Event event;
    while (SDL_PollEvent(&event)) {
        if (_handleApplicationInput(event)) { // Application has handled the event
            continue;
        }
        // TODO add check if GUI has handled any of the input
        if (_pCamera->handleInput(event)) { // Camera has handled the event
            continue;
        }
        if (_pScene->handleInput(event)) { // Scene is last thing to handle events
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
                // Set window size in Camera
                getCamera()->setWindowSize(windowWidth, windowHeight);
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

    _pCamera->update(passedTicks);
    _pScene->update(passedTicks);
}

void Application::_renderScene() {
    // Cleanup rendering buffers
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT | GL_STENCIL_BUFFER_BIT);

    _pScene->render();

    ImGui::Render();
    ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());

    SDL_GL_SwapWindow(_pWindow);
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