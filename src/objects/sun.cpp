#include "objects/sun.hpp"

#include "color.hpp"
#include "models/sphere.hpp"

Sun::Sun(Scene* pScene) {
    _pModel = new Sphere(_pTransform, _selected, color::yellow);
    pScene->addRenderable(_pModel);

    _pGuiBinding = new SunGuiBinding(this);

    _temperature.set(6000);
}

Sun::~Sun() {
    delete _pModel;
    delete _pGuiBinding;
}

void Sun::update(int t) {
}
