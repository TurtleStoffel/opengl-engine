#include "planetscene.hpp"

#include "application.hpp"
#include "objects/planet.hpp"

void PlanetScene::initialize() {
    // Set Camera values according to what is needed in the System Scene
    Application::instance()->getCamera()->set(glm::vec3(0.0f, 0.0f, 7.0f),
                                              glm::vec3(0.0f, 0.0f, -1.0f),
                                              glm::vec3(0.0f, 1.0f, 0.0f),
                                              Camera::MovementMode::SPHERICAL);

    _objects.push_back(new Planet(0.0f, 3.0f));
}
