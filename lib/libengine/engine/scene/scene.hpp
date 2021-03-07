#pragma once

#include "engine/camera.hpp"
#include "engine/guibinding/gui_factory.hpp"
#include "engine/objects/object.hpp"
#include "engine/opengl.hpp"

#include <vector>

class ShaderRegistry;

class Scene {
  public:
    Scene();
    virtual ~Scene() = default;

    auto update(int dt, const ShaderRegistry& shaderContainer) -> void;
    auto render(const ShaderRegistry& shaderContainer) -> void;

    auto handleInput(SDL_Event event) -> bool;
    auto setWindowSize(int windowWidth, int windowHeight) -> void;

  protected:
    virtual auto renderGui() -> void;

    std::vector<std::unique_ptr<Object>> m_objects;
    std::unique_ptr<Camera> m_camera;
    GuiFactory m_guiFactory;

  private:
    auto mousePick(SDL_Event event) -> void;
};