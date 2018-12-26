#ifndef APPLICATION_HPP
#define APPLICATION_HPP

#include <glm/glm.hpp>

#include "opengl.hpp"

#include "nanovg.h"

class Scene;

class Application {
   public:
    ~Application();

    static Application* pApplication;
    static Application* instance(SDL_Window* pWindow);
    static Application* instance();

    void run();
    void setScene(Scene* pScene);

    glm::mat4 _projectionMatrix;

    int _windowWidth;
    int _windowHeight;

   protected:
    Application(SDL_Window* pWindow);

   private:
    bool _handleInput(SDL_Event event);
    void _render();

    bool _running = true;

    Scene* _pScene;
    SDL_Window* _pWindow;
    GLuint _shader;
    NVGcontext* _vg;
};

#endif
