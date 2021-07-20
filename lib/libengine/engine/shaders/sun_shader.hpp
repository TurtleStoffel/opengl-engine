#pragma once

#include "engine/shaders/shader.hpp"

class SunShader final : public Shader {
  public:
    SunShader()
          : Shader{"shaders/sun/vertex.glsl", "shaders/sun/fragment.glsl"} {};
    ~SunShader() override = default;
};