#include "planetscene.hpp"

#include "flatcamera.hpp"

#include "objects/planet.hpp"

PlanetScene::PlanetScene() {
    _objects.push_back(new Planet(this));
    //_pCamera = new FlatCamera();
}
