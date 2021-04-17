#pragma once

#include <glm/glm.hpp>

namespace Engine::Components {
    class Transform;
}

class Collider {
  public:
    Collider(const Engine::Components::Transform* pTransform);

    /**
     * Intermediate implementation where Collider is always equal to a sphere
     */
    bool intersect(glm::vec3 rayPosition, glm::vec3 rayDirection);

  private:
    const Engine::Components::Transform* _pTransform;
};