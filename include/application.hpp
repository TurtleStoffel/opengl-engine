#ifndef APPLICATION_HPP
#define APPLICATION_HPP

#include <glm/glm.hpp>

#include "nanovg.h"

#include "opengl.hpp"
#include "scene.hpp"

class Application {
   public:
    ~Application();

    /**
     * Create new Application instance with a window, this method can only be called once in the
     * entire program, otherwise will throw error
     */
    static Application* createInstance(SDL_Window* pWindow);
    /**
     * Requests the current instance of the application, assumes one has been created before using
     * Application::createInstance(SDL_Window* pWindow)
     */
    static Application* instance();

    void run();
    void setScene(Scene* pScene);

   private:
    static Application* pApplication;
    Application(SDL_Window* pWindow);

    bool _handleInput(SDL_Event event);
    void _render();

    bool _running = true;

    Scene* _pScene;
    SDL_Window* _pWindow;
    NVGcontext* _vg;
};

#endif
