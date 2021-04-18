#pragma once

#include "engine/components/component.hpp"
#include "engine/components/transform.hpp"

#include <glm/glm.hpp>

namespace Engine::Components {
    class Transform;
}

namespace Engine::Components {
    /**
     * Detect whether a component has been selected
     */
    class Collider : public Component {
      public:
        Collider(Entity& entity);

        /**
         * Collider is always equal to a sphere
         */
        bool intersect(glm::vec3 rayPosition, glm::vec3 rayDirection);

        auto getSelected() const -> bool;

      private:
        Transform& m_transform;
        bool m_selected{false};
    };
}