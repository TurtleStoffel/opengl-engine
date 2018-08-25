#include "planetscene.hpp"

#include "flatcamera.hpp"

#include "objects/planet.hpp"

PlanetScene::PlanetScene(Application* pParent) : Scene(pParent) {
    _objects.push_back(new Planet(_shader, this));
    _camera = new FlatCamera(_shader);
}
