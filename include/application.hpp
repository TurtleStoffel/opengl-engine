#ifndef APPLICATION_HPP
#define APPLICATION_HPP

#include <glm/glm.hpp>

#include "opengl.hpp"

class Scene;

class Application {
   public:
    Application(SDL_Window* pWindow);
    ~Application();

    void run();
    void setScene(Scene* pScene);

   private:
    bool _handleInput(SDL_Event event);

    bool _running = true;

    Scene* _pScene;
    SDL_Window* _pWindow;
    GLuint _shader;

    int _windowWidth;
    int _windowHeight;

    glm::vec3 _cameraPosition  = glm::vec3(0.0f, -5.0f, 10.0f);
    glm::vec3 _cameraDirection = glm::vec3(0.0f, 0.8f, -1.0f);
    glm::vec3 _cameraUp        = glm::vec3(0.0f, 1.0f, 0.0f);
};

#endif
