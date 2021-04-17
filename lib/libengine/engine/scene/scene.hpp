#pragma once

#include "engine/camera.hpp"
#include "engine/guibinding/gui_factory.hpp"
#include "engine/objects/entity.hpp"
#include "engine/opengl.hpp"

#include <vector>

class ShaderRegistry;

class Scene {
  public:
    Scene(const ShaderRegistry& shaderRegistry);
    virtual ~Scene() = default;

    auto update(int dt) -> void;
    auto render() -> void;

    auto handleInput(SDL_Event event) -> bool;
    auto setWindowSize(int windowWidth, int windowHeight) -> void;

  protected:
    virtual auto renderGui() -> void;

    std::vector<std::unique_ptr<Engine::Entity>> m_objects;
    std::unique_ptr<Camera> m_camera;
    GuiFactory m_guiFactory;

    const ShaderRegistry& m_shaderRegistry;

  private:
    auto mousePick(SDL_Event event) -> void;
};