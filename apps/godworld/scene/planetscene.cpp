#include "planetscene.hpp"

#include "application.hpp"
#include "objects/planet.hpp"

void PlanetScene::initialize() {
    camera->setOrientation(glm::vec3(0.0f, 0.0f, 7.0f),
                           glm::vec3(0.0f, 0.0f, 0.0f),
                           glm::vec3(0.0f, 1.0f, 0.0f));
    camera->setSphericalMovement(7.0f);

    _objects.push_back(std::make_unique<Planet>(0.0f, 3.0f));
}
