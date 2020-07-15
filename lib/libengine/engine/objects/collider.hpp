#pragma once

#include <memory>

#include "transform.hpp"

class Collider {
  public:
    Collider(const Transform* pTransform);

    /**
     * Intermediate implementation where Collider is always equal to a sphere
     */
    bool intersect(glm::vec3 rayPosition, glm::vec3 rayDirection);

  private:
    const Transform* _pTransform;
};