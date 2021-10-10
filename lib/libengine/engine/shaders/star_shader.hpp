#pragma once

#include "engine/shaders/shader.hpp"

class StarShader final : public Engine::Shader {
  public:
    StarShader()
          : Engine::Shader{"shaders/star/vertex.glsl", "shaders/star/fragment.glsl"} {};
    ~StarShader() override = default;
};