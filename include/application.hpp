#ifndef APPLICATION_HPP
#define APPLICATION_HPP

#include <exception>

#include <glm/glm.hpp>

#include "gui/gui.hpp"
#include "scene/scene.hpp"

class Application {
  public:
    /**
     * Constructor can only be called once in the entire program, otherwise will throw error
     */
    Application(SDL_Window* pWindow);
    virtual ~Application();
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

  protected:
    std::unique_ptr<Scene> _pScene;

    virtual void _createScene() = 0;

  private:
    static Application* _pApplication;

    /**
     * Called at the start of the run method, because it requires the Application instance to
     * already exist.
     */
    void _setupApplication();

    void _handleInput();
    void _updateScene();
    void _renderScene();
    void _throttleFps();

    int _getTicksSinceLastUpdate();
    bool _handleApplicationInput(SDL_Event event);

    bool _running = true;
    int _lastFpsTicks;
    int _lastUpdateTicks;

    SDL_Window* _pWindow;
    gui::Gui* _pGui;
    std::unique_ptr<Camera> _pCamera;
};

#endif