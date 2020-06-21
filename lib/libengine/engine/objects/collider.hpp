#pragma once

#include "object.hpp"

class Collider {
  public:
    Collider(const Transform* pTransform);

    /**
     * Intermediate implementation where Collider is always equal to a sphere
     */
    bool intersect(glm::vec3 rayPosition, glm::vec3 rayDirection);

    // TODO
    // In the future change this to:
    //      virtual bool intersect(glm::vec3 rayPosition, glm::vec3 rayDirection) = 0;
    // so different implementation types of colliders are possible

    void setSelected(bool value);

    Property<bool>* getCollidedProperty();

  private:
    const Transform* _pTransform;

    std::unique_ptr<Property<bool>> _collided;
};