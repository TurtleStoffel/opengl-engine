#include "objects/sun.hpp"

#include "color.hpp"

#include "models/sphere.hpp"

Sun::Sun(Scene* pScene) {
    _pModel = new Sphere(_pTransform, _selected, color::yellow);
    pScene->addRenderable(_pModel);

    _temperature = 6000;
}

Sun::~Sun() {
    delete _pModel;
}

void Sun::update(int t) {
}
