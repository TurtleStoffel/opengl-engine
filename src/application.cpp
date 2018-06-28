#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

#include "application.hpp"
#include "shader.hpp"

#include "models/model.hpp"
#include "models/square.hpp"
#include "models/ground.hpp"

Application::Application() {
    SDL_Init(SDL_INIT_VIDEO);
    _pWindow =
        SDL_CreateWindow("GodWorld", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, _windowWidth,
                         _windowHeight, SDL_WINDOW_OPENGL | SDL_WINDOW_RESIZABLE);

    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 3);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 3);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);
    SDL_GLContext context = SDL_GL_CreateContext(_pWindow);

#ifndef __APPLE__
    glewExperimental = GL_TRUE;
    glewInit();
#endif

    glClearColor(0.0, 0.0, 0.2, 1.0);
    glEnable(GL_DEPTH_TEST);

    Shader shader = Shader("../shaders/vertex.glsl", "../shaders/fragment.glsl");
    shader.use();
    _shader = shader._ID;
}

Application::~Application() {
    SDL_DestroyWindow(_pWindow);
    SDL_Quit();
}

void Application::run() {
    GLuint modelMatrix = glGetUniformLocation(_shader, "model");
    GLuint viewMatrix = glGetUniformLocation(_shader, "view");
    GLuint projectionMatrix = glGetUniformLocation(_shader, "projection");

    glm::vec3 cameraPosition = glm::vec3(0.0f, -5.0f, 10.0f);
    glm::vec3 cameraDirection = glm::vec3(0.0f, 0.5f, -1.0f);
    glm::vec3 cameraUp = glm::vec3(0.0f, 1.0f, 0.0f);

    unsigned int lastFrame = SDL_GetTicks();
    Model *object = new Ground();

    while (!_stop) {
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        // TODO Optimize model/view/projection matrix
        glm::mat4 projection = glm::perspective(glm::radians(45.0f),
                                                (float)_windowWidth / _windowHeight, 0.1f, 100.0f);
        glUniformMatrix4fv(projectionMatrix, 1, GL_FALSE, &projection[0][0]);

        glm::mat4 view = glm::lookAt(cameraPosition, cameraPosition + cameraDirection, cameraUp);
        glUniformMatrix4fv(viewMatrix, 1, GL_FALSE, &view[0][0]);

        glm::mat4 model = glm::mat4(1.0);
        glUniformMatrix4fv(modelMatrix, 1, GL_FALSE, &model[0][0]);

        SDL_Event event;
        while (SDL_PollEvent(&event)) {
            switch (event.type) {
                case SDL_WINDOWEVENT:
                    if (event.window.event == SDL_WINDOWEVENT_RESIZED) {
                        _windowWidth = event.window.data1;
                        _windowHeight = event.window.data2;

                        glViewport(0, 0, _windowWidth, _windowHeight);
                    }
                    break;
                case SDL_QUIT:
                    _stop = true;
                    break;
                case SDL_KEYDOWN:
                    switch (event.key.keysym.sym) {
                        case SDLK_ESCAPE:
                            _stop = true;
                            break;
                        case SDLK_w:
                            cameraPosition += glm::vec3(0.0f, 0.1f, 0.0f);
                            break;
                        case SDLK_s:
                            cameraPosition += glm::vec3(0.0f, -0.1f, 0.0f);
                            break;
                        case SDLK_a:
                            cameraPosition += glm::vec3(-0.1f, 0.0f, 0.0f);
                            break;
                        case SDLK_d:
                            cameraPosition += glm::vec3(0.1f, 0.0f, 0.0f);
                            break;
                        case SDLK_z:
                            glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
                            break;
                        case SDLK_x:
                            glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
                            break;
                        default:
                            break;
                    }
                    break;
            }
        }

        object->render();

        SDL_GL_SwapWindow(_pWindow);

        // Limit number of frames per second
        unsigned int currentFrame = SDL_GetTicks();
        if (currentFrame - lastFrame < 1000 / FPS) {
            SDL_Delay(1000 / FPS - currentFrame + lastFrame);
        }
        lastFrame = currentFrame;
    }

    delete object;
}
