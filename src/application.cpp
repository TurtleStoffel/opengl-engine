#include "application.hpp"

#include <glm/gtc/matrix_transform.hpp>

#include "camera.hpp"
#include "const.hpp"
#include "planetscene.hpp"
#include "shader.hpp"
#include "shadercontainer.hpp"
#include "systemscene.hpp"

Application* Application::pApplication = nullptr;

Application::Application(SDL_Window* pWindow) {
    // Initialize data members
    _pWindow = pWindow;
    _pGui    = new Gui(pWindow);

    // Initialize all shaders
    ShaderContainer::init();

    SystemScene::setInitialScene();
}

Application* Application::createInstance(SDL_Window* pWindow) {
    // Only one instance of this class should ever be created, otherwise throw error
    assert(!pApplication);

    pApplication = new Application(pWindow);
    return pApplication;
}

Application* Application::instance() {
    assert(pApplication);

    return pApplication;
}

void Application::run() {
    int lastFPSTick     = SDL_GetTicks();
    int lastUpdateTicks = SDL_GetTicks();

    while (_running) {
        // ---Input handling---
        SDL_Event event;
        while (SDL_PollEvent(&event)) {
            if (!_handleInput(event)) {
                // Check if GUI handled input

                // GUI has precedence over Scene
                Scene::instance()->handleInput(event);
            }
        }

        // ---Scene Update---
        // Get number of ms since previous update
        int currentUpdateTicks = SDL_GetTicks();
        int passedTicks        = currentUpdateTicks - lastUpdateTicks;
        lastUpdateTicks        = currentUpdateTicks;
        // Update scene
        Scene::instance()->update(passedTicks);

        // ---Rendering---
        _render();

        // Limit number of frames per second
        int currentFPSTick = SDL_GetTicks();
        if (currentFPSTick - lastFPSTick < (1000 / constant::FPS)) {
            SDL_Delay(1000 / constant::FPS - currentFPSTick + lastFPSTick);
        }
        lastFPSTick = currentFPSTick;
    }
}

bool Application::_handleInput(SDL_Event event) {
    switch (event.type) {
        case SDL_WINDOWEVENT:
            if (event.window.event == SDL_WINDOWEVENT_RESIZED) {
                Camera::instance()->setWindowSize(event.window.data1,   // Window Width
                                                  event.window.data2);  // Window Height
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

void Application::_render() {
    // Cleanup rendering buffers
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT | GL_STENCIL_BUFFER_BIT);

    // Render scene
    Scene::instance()->render();

    // Render GUI on top of scene
    _pGui->render();

    // Swap window buffers
    SDL_GL_SwapWindow(_pWindow);
}
