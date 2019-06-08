#include "systemscene.hpp"

#include "flatcamera.hpp"
#include "objects/planet.hpp"
#include "objects/sun.hpp"
#include "planetscene.hpp"

Scene* SystemScene::setInitialScene() {
    // This method is only allowed to be called once
    assert(!_pScene);

    SystemScene* pScene = new SystemScene();
    _pScene             = pScene;
    pScene->_initialize();
    return _pScene;
}

SystemScene::SystemScene() {
}

void SystemScene::_changeScene() {
    assert(_pScene);

    delete _pScene;
    PlanetScene* pScene = new PlanetScene();
    _pScene             = pScene;
    pScene->_initialize();
}

void SystemScene::_initialize() {
    // Create camera
    _pCamera = FlatCamera::changeInstance();
    _pCamera->set(glm::vec3(0.0f, 0.0f, 5.0f),
                  glm::vec3(0.0f, 0.0f, -1.0f),
                  glm::vec3(0.0f, 1.0f, 0.0f));

    // Create objects
    _objects.push_back(new Sun(this));
    _objects.push_back(new Planet(this));
}
