#include "application.hpp"

#include <glm/gtc/matrix_transform.hpp>

#include "camera.hpp"
#include "const.hpp"
#include "planetscene.hpp"
#include "shader.hpp"
#include "shadercontainer.hpp"
#include "systemscene.hpp"

Application* Application::_pApplication = nullptr;

Application::Application(SDL_Window* pWindow) {
    // Set data members from constuctor input
    // Remainder of setup is automatically performed in _setup method before Program Loop
    _pWindow = pWindow;
}

Application* Application::createInstance(SDL_Window* pWindow) {
    // Only one instance of this class should ever be created, otherwise throw error
    assert(!_pApplication);

    _pApplication = new Application(pWindow);
    return _pApplication;
}

Application* Application::instance() {
    // Check that an instance of the Application already exists
    assert(_pApplication);

    return _pApplication;
}

void Application::run() {
    // Initial setup to make Application functional has to be done before program loop starts
    _setup();

    int lastFPSTick     = SDL_GetTicks();
    int lastUpdateTicks = SDL_GetTicks();

    while (_running) {
        // ---Input handling---
        SDL_Event event;
        while (SDL_PollEvent(&event)) {
            if (!_handleInput(event)) {
                // Check if GUI handled input

                // GUI has precedence over Scene
                _pScene->handleInput(event);
            }
        }

        // ---Scene Update---
        // Get number of ms since previous update
        int currentUpdateTicks = SDL_GetTicks();
        int passedTicks        = currentUpdateTicks - lastUpdateTicks;
        lastUpdateTicks        = currentUpdateTicks;
        // Update scene
        _pScene->update(passedTicks);

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

gui::Gui* Application::getGui() {
    return _pGui;
}

Camera* Application::getCamera() {
    return getScene()->getCamera();
}

Scene* Application::getScene() {
    // Check if this Application has a Scene, otherwise throw exception
    if (_pScene) {
        return _pScene.get();
    } else {
        throw ApplicationHasNoSceneInstance();
    }
}

void Application::_setup() {
    _pGui = new gui::Gui();

    // Initialize all shaders
    ShaderContainer::init();

    // Create the Scene
    _pScene = std::make_unique<SystemScene>();
    _pScene->initialize();
}

bool Application::_handleInput(SDL_Event event) {
    switch (event.type) {
        case SDL_WINDOWEVENT:
            if (event.window.event == SDL_WINDOWEVENT_RESIZED) {
                int windowWidth  = event.window.data1;
                int windowHeight = event.window.data2;
                // Set window size in Camera
                getCamera()->setWindowSize(windowWidth, windowHeight);

                // Set values in GUI
                _pGui->setWindowParameters(windowWidth, windowHeight);
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
    _pScene->render();

    // Render GUI on top of scene
    _pGui->render();

    // Swap window buffers
    SDL_GL_SwapWindow(_pWindow);
}
