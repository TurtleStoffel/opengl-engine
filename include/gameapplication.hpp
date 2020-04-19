#ifndef GAMEAPPLICATION_HPP
#define GAMEAPPLICATION_HPP

#include "application.hpp"

class GameApplication : public Application {
  public:
    GameApplication(SDL_Window* pWindow);
    virtual ~GameApplication();

  protected:
    virtual void _createScene();
};

#endif