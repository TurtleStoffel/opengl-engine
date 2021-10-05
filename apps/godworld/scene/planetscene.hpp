#pragma once

#include "engine/scene.hpp"

class ShaderRegistry;

class PlanetScene : public Engine::Scene {
  public:
    PlanetScene(const ShaderRegistry& shaderRegistry);
    ~PlanetScene() override = default;
};