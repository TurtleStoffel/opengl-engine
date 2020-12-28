#pragma once

#include "engine/camera.hpp"
#include "engine/guibinding/gui_factory.hpp"
#include "engine/objects/object.hpp"
#include "engine/opengl.hpp"

#include <vector>

class ShaderContainer;

class Scene {
  public:
    Scene();
    virtual ~Scene() = default;

    void update(int dt, const ShaderContainer& shaderContainer);
    void render(const ShaderContainer& shaderContainer);

    bool handleInput(SDL_Event event);
    void setWindowSize(int windowWidth, int windowHeight);

  protected:
    virtual void _renderGui(){};

    std::vector<std::unique_ptr<Object>> _objects;
    std::unique_ptr<Camera> camera;
    GuiFactory guiFactory = GuiFactory();

  private:
    void _mousePick(SDL_Event event);
};