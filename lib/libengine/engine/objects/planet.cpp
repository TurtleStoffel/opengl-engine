#include "planet.hpp"

#include <math.h>

#include "guibinding/planet_gui.hpp"
#include "models/effects/outline.hpp"
#include "models/sphere.hpp"
#include "objects/collider.hpp"
#include "util.hpp"

Planet::Planet(float distance, float radius) {
    model = std::make_unique<Sphere>(*transform.get());
    model->addEffect(std::make_unique<Outline>(*model.get()));

    guiBinding = std::make_unique<PlanetGui>(this);

    _rotationalSpeed = util::randf(0.00003f, 0.0001f);

    float rotationAngle = util::randRadian();

    transform->translate(
        glm::vec3(distance * sin(rotationAngle), distance * cos(rotationAngle), 0.0f));
    transform->scale(glm::vec3(radius, radius, radius));

    children.push_back(std::make_unique<Settlement>(this, glm::vec3(0.0f, 0.0f, radius * 1.5f)));
}

void Planet::update(int dt) {
    transform->rotateGlobal(_rotationalSpeed * dt);
}