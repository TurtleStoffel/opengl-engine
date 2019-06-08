#include "objects/sun.hpp"

#include <memory>

#include "color.hpp"
#include "models/sphere.hpp"
#include "objects/collider.hpp"

Sun::Sun(Scene* pScene) {
    _pModel = new Sphere(_pTransform, _pSelectionCollider->getCollidedProperty(), color::yellow);

    // Initialize Temperature Property
    _pTemperature               = new Property<int>();
    _propertyMap["Temperature"] = _pTemperature;

    _pGuiBinding = std::make_unique<SunGuiBinding>(this);

    // Update GUI when Property changes
    _pTemperature->addGenericCallback(
        std::bind(&SunGuiBinding::render, (SunGuiBinding*)(_pGuiBinding.get())));
    _pTemperature->set(6000);
}

Sun::~Sun() {
    delete _pModel;
    // _propertyMap contains reference to this pointer, but will go out of scope when this
    // destructor is called
    delete _pTemperature;
}

void Sun::update(int t) {
}
