#ifndef APPLICATION_HPP
#define APPLICATION_HPP

#include <glm/glm.hpp>

#include "gui/gui.hpp"
#include "scene.hpp"

class Application {
   public:
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

    gui::Gui* getGui();

   private:
    static Application* _pApplication;
    Application(SDL_Window* pWindow);

    /**
     * Initialize everything in the application to make it functional. Automatically called at the
     * start of the run method. If this is not used there might be issues if data in the setup
     * already requires the Application instance itself.
     */
    void _setup();

    bool _handleInput(SDL_Event event);
    void _render();

    bool _running = true;

    SDL_Window* _pWindow;
    gui::Gui* _pGui;
};

#endif
