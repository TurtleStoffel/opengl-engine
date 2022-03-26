#include "engine/shaders/lowpolyshader.hpp"

LowPolyShader::LowPolyShader()
      : Engine::Shader{"shaders/low-poly/vertex.glsl", "shaders/low-poly/fragment.glsl"} {
}

auto LowPolyShader::setStarPosition(const glm::vec4& starPosition) -> void {
    use();
    glUniform4fv(glGetUniformLocation(m_id, "starLocation"), 1, &starPosition[0]);
}