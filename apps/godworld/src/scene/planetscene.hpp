#pragma once

#include "engine/scene.hpp"
#include "engine/shaders/registry.hpp"

class PlanetScene : public Engine::Scene {
  public:
    PlanetScene(Engine::Shaders::Registry& shaderRegistry);
    ~PlanetScene() override = default;
};