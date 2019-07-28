#ifndef APPLICATION_HPP
#define APPLICATION_HPP

#include <exception>

#include <glm/glm.hpp>

#include "gui/gui.hpp"
#include "scene.hpp"

struct ApplicationHasNoSceneInstance : public std::exception {
    const char* what() const throw() {
        return "The current Application Instance does not have a Scene";
    }
};

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

    /**
     * The following methods return raw Pointers to some objects that have to be maintained in the
     * Program state
     * DO NOT CALL DELETE or store this Pointer! always request it again from the Application
     * instance
     */
    gui::Gui* getGui();
    Camera* getCamera();
    Scene* getScene();

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
    std::unique_ptr<Scene> _pScene;
};

#endif
