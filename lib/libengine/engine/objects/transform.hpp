#pragma once

#include <glm/glm.hpp>

class ShaderRegistry;

/**
 * Contains all information about location and orientation of an object, also has the required
 * information to calculate the model matrix
 */
class Transform {
  public:
    Transform() = default;
    Transform(Transform* parent);

    void scale(glm::vec3 v);
    auto setRelativePosition(const glm::vec3& position) -> void;
    void rotateLocal(float radians);

    auto getAbsolutePosition() const -> glm::vec3;
    auto getScale() const -> const glm::vec3&;

    void passModelMatrixToShader(const ShaderRegistry& shaderContainer) const;

  private:
    glm::mat4 calculateModelMatrix() const;

    Transform* m_parent{nullptr};

    glm::vec3 m_position = glm::vec3(0.0f, 0.0f, 0.0f);
    glm::vec3 m_scale    = glm::vec3(1.0f, 1.0f, 1.0f);

    // Local Rotation is around its own center
    float m_localRotation = 0.0f;
};