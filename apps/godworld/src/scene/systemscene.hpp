#pragma once

#include "engine/scene.hpp"
#include "engine/shaderregistry.hpp"

class SystemScene : public Engine::Scene {
  public:
    SystemScene(Engine::ShaderRegistry& shaderRegistry);
    ~SystemScene() override = default;
};