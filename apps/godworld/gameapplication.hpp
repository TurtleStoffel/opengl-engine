#pragma once

#include "engine/application.hpp"

class GameApplication : public Application {
  public:
    GameApplication(SDL_Window* pWindow);
    virtual ~GameApplication();

  protected:
    virtual void _createScene();
};