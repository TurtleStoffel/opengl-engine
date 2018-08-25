#include "application.hpp"

#include <glm/gtc/matrix_transform.hpp>

#include "const.hpp"
#include "shader.hpp"

#include "planetscene.hpp"

Application::Application(SDL_Window* pWindow) {
    _pWindow      = pWindow;
    _windowWidth  = constant::initialWindowWidth;
    _windowHeight = constant::initialWindowHeight;

    Shader shader = Shader("../shaders/vertex.glsl",
                           "../shaders/geometry.glsl",
                           "../shaders/fragment.glsl");
    shader.use();
    _shader = shader._ID;

    setScene(new PlanetScene());
}

Application::~Application() {
    delete _pScene;
}

void Application::run() {
    GLuint projectionMatrix = glGetUniformLocation(_shader, "projection");

    int lastFPSTick     = SDL_GetTicks();
    int lastUpdateTicks = SDL_GetTicks();

    while (_running) {
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        // Set projection matrix
        glm::mat4 projection = glm::perspective(glm::radians(45.0f),
                                                (float)_windowWidth / _windowHeight,
                                                0.1f,
                                                100.0f);
        glUniformMatrix4fv(projectionMatrix, 1, GL_FALSE, &projection[0][0]);

        SDL_Event event;
        while (SDL_PollEvent(&event)) {
            if (!_handleInput(event)) {
                _pScene->handleInput(event);
            }
        }

        // Get number of ms since previous update
        int currentUpdateTicks = SDL_GetTicks();
        int passedTicks        = currentUpdateTicks - lastUpdateTicks;
        lastUpdateTicks        = currentUpdateTicks;
        _pScene->update(passedTicks);

        _pScene->render();

        // Swap window buffers
        SDL_GL_SwapWindow(_pWindow);

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
                _windowWidth  = event.window.data1;
                _windowHeight = event.window.data2;

                glViewport(0, 0, _windowWidth, _windowHeight);
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
