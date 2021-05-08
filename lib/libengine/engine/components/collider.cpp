#include "engine/components/collider.hpp"

#include "engine/components/transform.hpp"
#include "engine/objects/entity.hpp"

#define GLM_ENABLE_EXPERIMENTAL
#include <glm/gtx/intersect.hpp>

namespace Engine::Components {
    Collider::Collider(Entity& entity)
          : Component{entity, "Collider"}
          , m_transform{entity.getRequired<Transform>()} {
    }

    bool Collider::intersect(glm::vec3 rayPosition, glm::vec3 rayDirection) {
        glm::vec3 intersectionPoint;
        glm::vec3 intersectionNormal;

        m_selected = glm::intersectRaySphere(rayPosition,
                                             glm::normalize(rayDirection),
                                             m_transform.getAbsolutePosition(),
                                             m_transform.getScale()[0], // Sphere has uniform Scale
                                             intersectionPoint,
                                             intersectionNormal);
        return m_selected;
    }

    auto Collider::getSelected() const -> bool {
        return m_selected;
    }
}