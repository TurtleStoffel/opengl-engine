#pragma once

#include "engine/shaders/shader.hpp"

#include <glm/glm.hpp>

namespace Engine {
    class LowPolyShader final : public Shader {
      public:
        LowPolyShader();
        ~LowPolyShader() override = default;

        auto setStarPosition(const glm::vec4& starPosition) -> void;
    };
}