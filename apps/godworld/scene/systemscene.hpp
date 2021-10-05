#pragma once

#include "engine/scene.hpp"

class ShaderRegistry;

class SystemScene : public Engine::Scene {
  public:
    SystemScene(const ShaderRegistry& shaderRegistry);
    ~SystemScene() override = default;
};