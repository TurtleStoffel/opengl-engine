#include "planetscene.hpp"

#include "objects/planet.hpp"

Scene* PlanetScene::setInitialScene() {
    assert(!_pScene);

    _pScene = new PlanetScene();
    return _pScene;
}

PlanetScene::PlanetScene() {
}

void PlanetScene::_changeScene() {
    // Changing should only occur when initial scene has already been set
    assert(_pScene);

    delete _pScene;
    //_pScene = new SystemScene();
}

void PlanetScene::_initialize() {
    // TODO
}
