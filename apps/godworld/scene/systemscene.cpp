#include "systemscene.hpp"

#include "engine/application.hpp"
#include "engine/objects/planet.hpp"
#include "engine/objects/sun.hpp"
#include "engine/util.hpp"

SystemScene::SystemScene() {
    // Create objects
    _objects.push_back(std::make_unique<Sun>(guiFactory));
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
