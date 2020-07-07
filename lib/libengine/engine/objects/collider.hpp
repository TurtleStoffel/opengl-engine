#pragma once

#include <memory>

#include "transform.hpp"

#include "util/property.hpp"

class Collider {
  public:
    Collider(const Transform* pTransform);

    /**
     * Intermediate implementation where Collider is always equal to a sphere
     */
    bool intersect(glm::vec3 rayPosition, glm::vec3 rayDirection);

    Property<bool>* getCollidedProperty();

  private:
    const Transform* _pTransform;

    std::unique_ptr<Property<bool>> _collided;
};