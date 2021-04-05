#pragma once

#include "engine/scene/scene.hpp"

class ShaderRegistry;

class PlanetScene : public Scene {
  public:
    PlanetScene(const ShaderRegistry& shaderRegistry);
    ~PlanetScene() override = default;
};