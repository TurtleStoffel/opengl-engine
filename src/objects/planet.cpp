#include "objects/planet.hpp"

#include "models/sphere.hpp"

Planet::Planet(Scene* pScene) {
    _pModel = new Sphere();
    pScene->addRenderable(_pModel);
}

Planet::~Planet() {
    delete _pModel;
}
