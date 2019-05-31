#include "objects/sun.hpp"

#include "color.hpp"
#include "models/sphere.hpp"

Sun::Sun(Scene* pScene) {
    _pModel = new Sphere(_pTransform, _selected, color::yellow);
    pScene->addRenderable(_pModel);

    _pGuiBinding = new SunGuiBinding(this);

    // Initialize Temperature Property
    _temperature.addCallback([this](int newTemperature) -> void {
        _propertyMap["Temperature"] = std::to_string(newTemperature);
    });
    // Update GUI when Property changes
    _temperature.addGenericCallback(
        std::bind(&SunGuiBinding::render, (SunGuiBinding*)_pGuiBinding));
    _temperature.set(6000);
}

Sun::~Sun() {
    delete _pModel;
    delete _pGuiBinding;
}

void Sun::update(int t) {
}
