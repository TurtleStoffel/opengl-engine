#pragma once

#include "engine/shaders/shader.hpp"

#include <glm/glm.hpp>

namespace Engine::Shaders {
    class LowPoly final : public Shader {
      public:
        LowPoly();
        ~LowPoly() override = default;

        auto setStarPosition(const glm::vec4& starPosition) -> void;
    };
}