#pragma once

#include "engine/shaders/shader.hpp"

#include <glm/glm.hpp>

class LowPolyShader final : public Engine::Shader {
  public:
    LowPolyShader();
    ~LowPolyShader() override = default;
};