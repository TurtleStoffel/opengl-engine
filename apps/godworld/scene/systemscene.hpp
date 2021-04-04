#pragma once

#include "engine/scene/scene.hpp"

class SystemScene : public Scene {
  public:
    SystemScene(const ShaderRegistry& shaderRegistry);
    ~SystemScene() override = default;
};