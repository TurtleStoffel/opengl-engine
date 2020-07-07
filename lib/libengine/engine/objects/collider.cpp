#include "collider.hpp"

#define GLM_ENABLE_EXPERIMENTAL
#include <glm/gtx/intersect.hpp>

#include "application.hpp"

Collider::Collider(const Transform* pTransform) {
    _pTransform = pTransform;
    _collided   = std::make_unique<Property<bool>>();
}

bool Collider::intersect(glm::vec3 rayPosition, glm::vec3 rayDirection) {
    glm::vec3 intersectionPoint;
    glm::vec3 intersectionNormal;
    _collided->set(glm::intersectRaySphere(rayPosition,
                                   glm::normalize(rayDirection),
                                   _pTransform->getPosition(),
                                   _pTransform->getScale()[0], // Sphere has uniform Scale
                                   intersectionPoint,
                                   intersectionNormal));
    return _collided->value();
}

Property<bool>* Collider::getCollidedProperty() {
    return _collided.get();
}
