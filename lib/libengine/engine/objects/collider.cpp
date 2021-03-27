#include "engine/objects/collider.hpp"

#include "engine/application.hpp"

#define GLM_ENABLE_EXPERIMENTAL
#include <glm/gtx/intersect.hpp>

Collider::Collider(const Transform* pTransform) {
    _pTransform = pTransform;
}

bool Collider::intersect(glm::vec3 rayPosition, glm::vec3 rayDirection) {
    glm::vec3 intersectionPoint;
    glm::vec3 intersectionNormal;
    return glm::intersectRaySphere(rayPosition,
                                   glm::normalize(rayDirection),
                                   _pTransform->getAbsolutePosition(),
                                   _pTransform->getScale()[0], // Sphere has uniform Scale
                                   intersectionPoint,
                                   intersectionNormal);
}