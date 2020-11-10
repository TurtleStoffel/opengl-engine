#include "planetscene.hpp"

#include "application.hpp"
#include "objects/planet.hpp"

PlanetScene::PlanetScene() {
    _objects.push_back(std::make_unique<Planet>(0.0f, 3.0f));
}
