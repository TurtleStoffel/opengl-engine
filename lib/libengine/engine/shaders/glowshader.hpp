#pragma once

#include "engine/shaders/shader.hpp"

class GlowShader final : public Shader {
  public:
    GlowShader();
    ~GlowShader() override = default;
};