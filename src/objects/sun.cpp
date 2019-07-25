#include "objects/sun.hpp"

#include <memory>

#include "color.hpp"
#include "models/sphere.hpp"
#include "objects/collider.hpp"

Sun::Sun() {
    _pModel = new Sphere(_pTransform, _pSelectionCollider->getCollidedProperty(), color::yellow);

    // Initialize Temperature Property
    _pTemperature               = new Property<int>();
    _propertyMap["Temperature"] = _pTemperature;

    // TODO Remove this Test Code
    Property<int>* testProperty = new Property<int>();
    _propertyMap["Test"]        = testProperty;
    // TODO end Test Code

    _pGuiBinding = std::make_unique<GuiBinding>(this);

    // Update GUI when Property changes
    _pTemperature->set(6000);

    // Update GUI when Property changes
    testProperty->set(32);
}

Sun::~Sun() {
    delete _pModel;
    // _propertyMap contains reference to this pointer, but will go out of scope when this
    // destructor is called
    delete _pTemperature;
}

void Sun::update(int t) {
}
