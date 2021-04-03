#include "engine/objects/transform.hpp"

#include "engine/shaders/shaderregistry.hpp"

#define GLM_ENABLE_EXPERIMENTAL
#include <glm/gtx/transform.hpp>

Transform::Transform(Transform* parent)
      : m_parent{parent} {
}

auto Transform::scale(glm::vec3 v) -> void {
    m_scale *= v;
}

auto Transform::setRelativePosition(const glm::vec3& position) -> void {
    m_position = position;
}

auto Transform::rotateLocal(float radians) -> void {
    m_rotation += radians;
}

auto Transform::getRelativePosition() const -> const glm::vec3& {
    return m_position;
}

auto Transform::getAbsolutePosition() const -> glm::vec3 {
    glm::vec4 transformedPosition = calculateModelMatrix() * glm::vec4(0.0f, 0.0f, 0.0f, 1.0f);
    return glm::vec3(transformedPosition.x, transformedPosition.y, transformedPosition.z);
}

auto Transform::getScale() const -> const glm::vec3& {
    return m_scale;
}

auto Transform::passModelMatrixToShader(const ShaderRegistry& shaderContainer) const -> void {
    glm::mat4 modelMatrix = calculateModelMatrix();

    // Apply model transformation matrix
    shaderContainer.setModelMatrix(&modelMatrix[0][0]);
}

auto Transform::calculateModelMatrix() const -> glm::mat4 {
    glm::mat4 scaleMatrix         = glm::scale(m_scale);
    glm::mat4 localRotationMatrix = glm::rotate(m_rotation, glm::vec3(0.0f, 0.0f, 1.0f));
    glm::mat4 translateMatrix     = glm::translate(m_position);

    glm::mat4 modelMatrix = translateMatrix * localRotationMatrix * scaleMatrix;

    if (m_parent) {
        modelMatrix = m_parent->calculateModelMatrix() * modelMatrix;
    }

    return modelMatrix;
}
