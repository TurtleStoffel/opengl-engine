#pragma once

#include <vector>

#include "opengl.hpp"

#include "camera.hpp"
#include "guibinding/gui_factory.hpp"
#include "models/model.hpp"
#include "objects/object.hpp"

class Scene {
  public:
    Scene();
    virtual ~Scene(){};

    bool handleInput(SDL_Event event);
    void render();
    void setWindowSize(int windowWidth, int windowHeight);

    virtual void update(int t);

  protected:
    virtual void _renderGui(){};

    std::vector<std::unique_ptr<Object>> _objects;
    std::unique_ptr<Camera> camera;
    GuiFactory guiFactory = GuiFactory();

  private:
    void _mousePick(SDL_Event event);
};