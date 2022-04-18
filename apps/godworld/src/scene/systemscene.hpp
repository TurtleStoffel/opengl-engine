#pragma once

#include "engine/scene.hpp"
#include "engine/shaders/registry.hpp"

class SystemScene : public Engine::Scene {
  public:
    SystemScene(Engine::Shaders::Registry& shaderRegistry);
    ~SystemScene() override = default;
};