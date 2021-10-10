#include "engine/shaders/lowpolyshader.hpp"

LowPolyShader::LowPolyShader()
      : Engine::Shader{"shaders/low-poly/vertex.glsl", "shaders/low-poly/fragment.glsl"} {
}

auto LowPolyShader::setSettlementPosition(const glm::vec3& position) const -> void {
    glUniform1i(glGetUniformLocation(m_id, "isSettlementEnabled"), 1);
    glUniform3fv(glGetUniformLocation(m_id, "localSettlementPosition"), 1, &position[0]);
}