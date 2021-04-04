#pragma once

#include "engine/scene/scene.hpp"

class PlanetScene : public Scene {
  public:
    PlanetScene(const ShaderRegistry& shaderRegistry);
    ~PlanetScene() override = default;
};