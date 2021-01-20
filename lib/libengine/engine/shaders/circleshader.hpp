#pragma once

#include "engine/shaders/shader.hpp"

#include <glm/glm.hpp>

class CircleShader final : public Shader {
  public:
    CircleShader();
    ~CircleShader() override = default;

    auto setCirclePosition(const glm::vec3& position) const -> void;
};