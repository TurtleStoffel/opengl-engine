#include "application.hpp"

#include <glm/gtc/matrix_transform.hpp>

#include "const.hpp"
#include "scene.hpp"
#include "shader.hpp"

#include "models/ground.hpp"
#include "models/model.hpp"
#include "models/square.hpp"

Application::Application(SDL_Window* pWindow) {
    _pWindow      = pWindow;
    _windowWidth  = constant::initialWindowWidth;
    _windowHeight = constant::initialWindowHeight;

    Shader shader = Shader("../shaders/vertex.glsl",
                           "../shaders/geometry.glsl",
                           "../shaders/fragment.glsl");
    shader.use();
    _shader = shader._ID;

    setScene(new Scene());
}

Application::~Application() {
    delete _pScene;
}

void Application::run() {
    GLuint modelMatrix          = glGetUniformLocation(_shader, "model");
    GLuint viewMatrix           = glGetUniformLocation(_shader, "view");
    GLuint projectionMatrix     = glGetUniformLocation(_shader, "projection");
    GLuint shaderCameraPosition = glGetUniformLocation(_shader, "cameraPosition");

    int lastFrame = SDL_GetTicks();

    while (_running) {
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        // TODO Optimize model/view/projection matrix
        glm::mat4 projection = glm::perspective(glm::radians(45.0f),
                                                (float)_windowWidth / _windowHeight,
                                                0.1f,
                                                100.0f);
        glUniformMatrix4fv(projectionMatrix, 1, GL_FALSE, &projection[0][0]);

        glm::mat4 view = glm::lookAt(_cameraPosition,
                                     _cameraPosition + _cameraDirection,
                                     _cameraUp);
        glUniformMatrix4fv(viewMatrix, 1, GL_FALSE, &view[0][0]);

        glm::mat4 model = glm::mat4(1.0);
        glUniformMatrix4fv(modelMatrix, 1, GL_FALSE, &model[0][0]);

        glUniform3fv(shaderCameraPosition, 1, &_cameraPosition[0]);

        SDL_Event event;
        while (SDL_PollEvent(&event)) {
            if (!_handleInput(event)) {
                _pScene->handleInput(event);
            }
        }

        _pScene->render();

        SDL_GL_SwapWindow(_pWindow);

        // Limit number of frames per second
        int currentFrame = SDL_GetTicks();
        if (currentFrame - lastFrame < 1000 / constant::FPS) {
            SDL_Delay(1000 / constant::FPS - currentFrame + lastFrame);
        }
        lastFrame = currentFrame;
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
                case SDLK_w:
                    _cameraPosition += glm::vec3(0.0f, 0.1f, 0.0f);
                    return true;
                case SDLK_s:
                    _cameraPosition += glm::vec3(0.0f, -0.1f, 0.0f);
                    return true;
                case SDLK_a:
                    _cameraPosition += glm::vec3(-0.1f, 0.0f, 0.0f);
                    return true;
                case SDLK_d:
                    _cameraPosition += glm::vec3(0.1f, 0.0f, 0.0f);
                    break;
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
