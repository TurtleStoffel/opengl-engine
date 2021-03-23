#pragma once

#include "engine/shaders/shader.hpp"

class BackgroundShader final : public Shader {
  public:
    BackgroundShader()
        : Shader{"shaders/background/vertex.glsl", "shaders/background/fragment.glsl"} {
    }
};