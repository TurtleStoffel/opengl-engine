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
    // Remainder of setup is automatically performed in _setupApplication method before Program Loop
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
    _setupApplication();

    while (_running) {
        _handleInput();
        _updateScene();
        _renderScene();
        _throttleFps();
    }
}

gui::Gui* Application::getGui() {
    return _pGui;
}

Camera* Application::getCamera() {
    // Check if this Application has a Camera, otherwise throw exception
    if (_pCamera) {
        return _pCamera.get();
    } else {
        throw ApplicationHasNoCameraInstance();
    }
}

Scene* Application::getScene() {
    // Check if this Application has a Scene, otherwise throw exception
    if (_pScene) {
        return _pScene.get();
    } else {
        throw ApplicationHasNoSceneInstance();
    }
}

void Application::_setupApplication() {
    // Initialize all shaders
    ShaderContainer::init();

    _pGui = new gui::Gui();

    _pCamera = std::make_unique<Camera>();

    // Create the Scene
    // System Scene
    /*
    _pScene = std::make_unique<SystemScene>();
    _pScene->initialize();
    */
    // Planet Scene
    _pScene = std::make_unique<PlanetScene>();
    _pScene->initialize();

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

void Application::_updateScene() {
    int passedTicks = _getTicksSinceLastUpdate();

    _pCamera->update(passedTicks);
    _pScene->update(passedTicks);
}

void Application::_renderScene() {
    // Cleanup rendering buffers
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT | GL_STENCIL_BUFFER_BIT);

    _pScene->render();

    // Render GUI on top of scene
    _pGui->render();

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