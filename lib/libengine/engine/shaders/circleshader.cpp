#include "engine/shaders/circleshader.hpp"

CircleShader::CircleShader()
      : Engine::Shader{"shaders/circle/vertex.glsl", "shaders/circle/fragment.glsl"} {
}

auto CircleShader::setCirclePosition(const glm::vec3& position) const -> void {
    glUniform3fv(glGetUniformLocation(m_id, "circlePosition"), 1, &position[0]);
}