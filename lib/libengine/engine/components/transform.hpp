#pragma once

#include "engine/components/component.hpp"

#include <glm/glm.hpp>

namespace ModelViewer {
    class ModelScene;
}

class ShaderRegistry;

namespace Engine::Components {
    /**
     * Contains all information about location and orientation of an object, also has the required
     * information to calculate the model matrix
     *
     * Transform is an immediate component of Entity even though it is used by the Model, because
     * an entity needs a notion of where it is even when it has no model (e.g. only load model when
     * objects will be visible)
     */
    class Transform : public Engine::Components::Component {
        friend class ModelViewer::ModelScene;

      public:
        Transform(Engine::Entity& object);

        auto scale(glm::vec3 v) -> void;
        auto setRelativePosition(const glm::vec3& position) -> void;
        auto setRotation(const glm::vec3& rotation) -> void;

        auto getRelativePosition() const -> const glm::vec3&;
        auto getAbsolutePosition() const -> glm::vec3;
        auto getScale() const -> const glm::vec3&;
        auto getRotation() const -> const glm::vec3&;

        auto passModelMatrixToShader(const ShaderRegistry& shaderContainer) const -> void;

      private:
        auto calculateModelMatrix() const -> glm::mat4;

        Transform* m_parent{nullptr};

        glm::vec3 m_position    = glm::vec3{0.0f, 0.0f, 0.0f};
        glm::vec3 m_scale       = glm::vec3{1.0f, 1.0f, 1.0f};
        glm::vec3 m_rotationYXZ = glm::vec3{0.0f, 0.0f, 0.0f};
    };
}