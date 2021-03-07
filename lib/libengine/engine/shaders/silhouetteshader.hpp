#pragma once

#include "engine/shaders/shader.hpp"

class SilhouetteShader final : public Shader {
  public:
    SilhouetteShader();
    ~SilhouetteShader() override = default;
};