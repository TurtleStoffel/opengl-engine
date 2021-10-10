#pragma once

#include "engine/shaders/shader.hpp"

class BackgroundShader final : public Engine::Shader {
  public:
    BackgroundShader()
          : Engine::Shader{"shaders/background/vertex.glsl", "shaders/background/fragment.glsl"} {
    }
};