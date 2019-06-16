#include "objects/planet.hpp"

#include <math.h>

#include "models/sphere.hpp"
#include "objects/collider.hpp"
#include "util.hpp"

Planet::Planet(float distance, float radius) {
    _pModel = new Sphere(_pTransform, _pSelectionCollider->getCollidedProperty());

    _rotationalSpeed = util::randf(0.00003f, 0.0001f);

    float rotationAngle = util::randRadian();

    _pTransform->translate(
        glm::vec3(distance * sin(rotationAngle), distance * cos(rotationAngle), 0.0f));
    _pTransform->scale(glm::vec3(radius, radius, radius));
}

Planet::~Planet() {
    delete _pModel;
}

void Planet::update(int t) {
    _pTransform->rotateGlobal(_rotationalSpeed * t);
}
