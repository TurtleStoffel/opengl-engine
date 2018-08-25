#include "objects/sun.hpp"

#include "models/sphere.hpp"

Sun::Sun(Scene* pScene) {
    _pModel = new Sphere();
    pScene->addRenderable(_pModel);
}

Sun::~Sun() {
    delete _pModel;
}
