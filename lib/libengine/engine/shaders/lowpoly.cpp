#include "engine/shaders/lowpoly.hpp"

namespace Engine::Shaders {
    LowPoly::LowPoly()
          : Shader{"shaders/low-poly/vertex.glsl", "shaders/low-poly/fragment.glsl"} {
    }

    auto LowPoly::setStarPosition(const glm::vec4& starPosition) -> void {
        use();
        glUniform4fv(glGetUniformLocation(m_id, "starLocation"), 1, &starPosition[0]);
    }
}