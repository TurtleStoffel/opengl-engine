#pragma once

#include <vector>

#include "opengl.hpp"

#include "camera.hpp"
#include "guibinding/gui_factory.hpp"
#include "models/model.hpp"
#include "objects/object.hpp"

class Scene {
  public:
    virtual ~Scene(){};

    bool handleInput(SDL_Event event);
    void render();

    virtual void update(int t);
    virtual void initialize() = 0;

  protected:
    virtual void _renderGui(){};

    std::vector<std::unique_ptr<Object>> _objects;
    GuiFactory guiFactory = GuiFactory();

  private:
    void _mousePick(SDL_Event event);
};