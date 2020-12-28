#include "planetscene.hpp"

#include "engine/application.hpp"
#include "engine/objects/planet.hpp"

PlanetScene::PlanetScene() {
    _objects.push_back(std::make_unique<Planet>(0.0f, 3.0f));
}
