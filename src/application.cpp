#include "application.hpp"

#include <glm/gtc/matrix_transform.hpp>

#define NANOVG_GL3_IMPLEMENTATION
#include "nanovg_gl.h"

#include "const.hpp"
#include "shader.hpp"
#include "shadercontainer.hpp"

#include "camera.hpp"
#include "planetscene.hpp"
#include "systemscene.hpp"

#include <iostream>

Application* Application::pApplication = nullptr;

Application::Application(SDL_Window* pWindow) {
    // Initialize data members
    _pWindow = pWindow;
    _vg      = nvgCreateGL3(NVG_ANTIALIAS);

    // Initialize all shaders
    ShaderContainer::init();

    setScene(new SystemScene());
}

Application::~Application() {
    delete _pScene;

    nvgDeleteGL3(_vg);
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

void Application::setScene(Scene* pScene) {
    _pScene = pScene;
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
    _pScene->render();

    // Render GUI
    int x = 50;
    int y = 50;
    int w = 120;
    int h = 30;

    // Get window Size for to start NanoVG frame
    int bufferWidth;
    int bufferHeight;
    SDL_GL_GetDrawableSize(_pWindow, &bufferWidth, &bufferHeight);

    int windowWidth;
    int windowHeight;
    Camera::instance()->getWindowSize(windowWidth, windowHeight);
    nvgBeginFrame(_vg, windowWidth, windowHeight, (float)bufferWidth / windowHeight);

    nvgSave(_vg);

    nvgBeginPath(_vg);
    nvgRect(_vg, x, y, w, h);
    nvgFillColor(_vg, nvgRGBA(255, 192, 0, 255));
    nvgFill(_vg);

    if (nvgCreateFont(_vg, "sans", "../res/Roboto-Regular.ttf") == -1) {
        std::cout << "could not open font" << std::endl;
    }

    nvgFontSize(_vg, 30.0f);
    nvgFontFace(_vg, "sans");
    nvgTextAlign(_vg, NVG_ALIGN_LEFT | NVG_ALIGN_MIDDLE);

    nvgFillColor(_vg, nvgRGBA(255, 255, 255, 255));
    nvgText(_vg, x + 5, y + h / 2, "test", NULL);

    nvgRestore(_vg);

    nvgEndFrame(_vg);

    // Restore variables edited by NanoVG
    glDisable(GL_BLEND);
    glEnable(GL_DEPTH_TEST);

    // Swap window buffers
    SDL_GL_SwapWindow(_pWindow);
}
