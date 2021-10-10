#pragma once

#include "engine/shaders/shader.hpp"

class SilhouetteShader final : public Engine::Shader {
  public:
    SilhouetteShader();
    ~SilhouetteShader() override = default;
};