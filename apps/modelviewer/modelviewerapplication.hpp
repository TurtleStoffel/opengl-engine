#pragma once

#include "engine/application.hpp"

class ModelViewerApplication : public Application {
  public:
    ModelViewerApplication(SDL_Window* pWindow);
    ~ModelViewerApplication() override = default;

  protected:
    virtual void _createScene();
};