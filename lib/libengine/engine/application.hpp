#pragma once

#include "engine/scene/scene.hpp"
#include "engine/shaders/shaderregistry.hpp"

#include <SDL2/SDL.h>
#include <memory>

struct SDL_Window;

class Application {
  public:
    /**
     * Constructor can only be called once in the entire program, otherwise will throw error
     */
    Application(SDL_Window* pWindow);
    virtual ~Application() = default;

    void run();

  protected:
    ShaderRegistry shaderContainer;

    std::unique_ptr<Scene> scene;

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

    SDL_Window* window;
};