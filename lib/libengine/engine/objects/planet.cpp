#include "planet.hpp"

#include <math.h>

#include "guibinding/planetguibinding.hpp"
#include "models/sphere.hpp"
#include "objects/collider.hpp"
#include "util.hpp"

Planet::Planet(float distance, float radius) {
    _pModel = std::make_unique<Sphere>(_pTransform.get());

    _pGuiBinding = std::make_unique<PlanetGuiBinding>(this);

    _rotationalSpeed = util::randf(0.00003f, 0.0001f);

    float rotationAngle = util::randRadian();

    _pTransform->translate(
        glm::vec3(distance * sin(rotationAngle), distance * cos(rotationAngle), 0.0f));
    _pTransform->scale(glm::vec3(radius, radius, radius));
}

void Planet::update(int t) {
    _pTransform->rotateGlobal(_rotationalSpeed * t);
}
