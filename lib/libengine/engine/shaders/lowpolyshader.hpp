#pragma once

#include "engine/shaders/shader.hpp"

#include <glm/glm.hpp>

class LowPolyShader final : public Shader {
  public:
    LowPolyShader();
    ~LowPolyShader() override = default;

    auto setSettlementPosition(const glm::vec3& position) const -> void;
};