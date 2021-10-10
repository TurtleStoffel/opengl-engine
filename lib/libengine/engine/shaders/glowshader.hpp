#pragma once

#include "engine/shaders/shader.hpp"

class GlowShader final : public Engine::Shader {
  public:
    GlowShader();
    ~GlowShader() override = default;
};