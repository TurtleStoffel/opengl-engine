#include "planet.hpp"

#include <math.h>

#include "models/sphere.hpp"
#include "objects/collider.hpp"
#include "util.hpp"

Planet::Planet(float distance, float radius) {
    _pModel = new Sphere(_pTransform, _pSelectionCollider->getCollidedProperty());

    _pOwnership               = new Property<float>();
    _propertyMap["Ownership"] = _pOwnership;

    _pInhabitants               = new Property<int>();
    _propertyMap["Inhabitants"] = _pInhabitants;

    _pGuiBinding = std::make_unique<GuiBinding>(this);

    _pOwnership->set(0.0f);
    _pInhabitants->set(5000);

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
