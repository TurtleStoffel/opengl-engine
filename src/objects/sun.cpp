#include "objects/sun.hpp"

#include "color.hpp"

#include "models/sphere.hpp"

Sun::Sun(Scene* pScene) {
    _pModel = new Sphere(color::yellow);
    pScene->addRenderable(_pModel);
}

Sun::~Sun() {
    delete _pModel;
}

void Sun::update(int t) {
}
