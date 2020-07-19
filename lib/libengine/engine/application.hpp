#pragma once

#include <exception>

#include <glm/glm.hpp>

#include "scene/scene.hpp"

class Application {
  public:
    /**
     * Constructor can only be called once in the entire program, otherwise will throw error
     */
    Application(SDL_Window* pWindow);
    virtual ~Application(){};

    void run();

  protected:
    std::unique_ptr<Scene> _pScene;

    virtual void _createScene() = 0;

  private:
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
};