#pragma once

#include "engine/scene.hpp"
#include "engine/shaderregistry.hpp"

class PlanetScene : public Engine::Scene {
  public:
    PlanetScene(Engine::ShaderRegistry& shaderRegistry);
    ~PlanetScene() override = default;
};