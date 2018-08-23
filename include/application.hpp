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

    GLuint getShaderID();

   private:
    bool _handleInput(SDL_Event event);

    bool _running = true;

    Scene* _pScene;
    SDL_Window* _pWindow;
    GLuint _shader;

    int _windowWidth;
    int _windowHeight;
};

#endif
