#pragma once

#include "engine/shaders/shader.hpp"

class LowPolyShader final : public Shader {
  public:
    LowPolyShader();
    ~LowPolyShader() override = default;

    auto setCameraPosition(GLfloat* position) const -> void;
};