#include "systemscene.hpp"

#include "application.hpp"
#include "objects/planet.hpp"
#include "objects/sun.hpp"
#include "util.hpp"

void SystemScene::initialize() {
    // Set Camera values according to what is needed in the System Scene
    Application::instance()->getCamera()->setOrientation(glm::vec3(0.0f, 0.0f, 15.0f),
                                                         glm::vec3(0.0f, 0.0f, 0.0f),
                                                         glm::vec3(0.0f, 1.0f, 0.0f));
    Application::instance()->getCamera()->setFlatMovement();

    // Create objects
    _objects.push_back(std::make_unique<Sun>());
    float minPlanetOffset = 2.0f;
    float maxPlanetOffset = 3.0f;
    float minPlanetRadius = 0.3f;
    float maxPlanetRadius = 0.8f;

    float currentPlanetOffset = 3.0f;

    for (int i = 0; i < util::randi(1, 3); i++) {
        currentPlanetOffset += util::randf(minPlanetOffset, maxPlanetOffset);
        float planetRadius = util::randf(minPlanetRadius, maxPlanetRadius);
        _objects.push_back(std::make_unique<Planet>(currentPlanetOffset, planetRadius));
    }
}
