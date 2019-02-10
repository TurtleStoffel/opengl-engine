#include "planetscene.hpp"

#include "flatcamera.hpp"

#include "objects/planet.hpp"

Scene* PlanetScene::setInitialScene() {
    assert(!_pScene);

    _pScene = new PlanetScene();
    return _pScene;
}

PlanetScene::PlanetScene() {
    _objects.push_back(new Planet(this));
    //_pCamera = new FlatCamera();
}

void PlanetScene::_changeScene() {
    // Changing should only occur when initial scene has already been set
    assert(_pScene);

    delete _pScene;
    _pScene = new SystemScene();
}
