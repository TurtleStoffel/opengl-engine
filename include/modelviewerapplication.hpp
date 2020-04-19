#ifndef MODELVIEWERAPPLICATION_HPP
#define MODELVIEWERAPPLICATION_HPP

#include "application.hpp"

class ModelViewerApplication : public Application {
  public:
    ModelViewerApplication(SDL_Window* pWindow);
    virtual ~ModelViewerApplication();

  protected:
    virtual void _createScene();
};

#endif