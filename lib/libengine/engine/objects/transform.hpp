#pragma once

#include <glm/glm.hpp>

namespace ModelViewer {
    class ModelScene;
}

class ShaderRegistry;

/**
 * Contains all information about location and orientation of an object, also has the required
 * information to calculate the model matrix
 */
class Transform {
    friend class ModelViewer::ModelScene;

  public:
    Transform() = default;
    Transform(Transform* parent);

    auto scale(glm::vec3 v) -> void;
    auto setRelativePosition(const glm::vec3& position) -> void;
    auto rotateLocal(float radians) -> void;

    auto getRelativePosition() const -> const glm::vec3&;
    auto getAbsolutePosition() const -> glm::vec3;
    auto getScale() const -> const glm::vec3&;

    auto passModelMatrixToShader(const ShaderRegistry& shaderContainer) const -> void;

  private:
    auto calculateModelMatrix() const -> glm::mat4;

    Transform* m_parent{nullptr};

    glm::vec3 m_position = glm::vec3(0.0f, 0.0f, 0.0f);
    glm::vec3 m_scale    = glm::vec3(1.0f, 1.0f, 1.0f);

    // Rotation around z-axis
    float m_rotation = 0.0f;
};