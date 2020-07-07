#include "sun.hpp"

#include <memory>

#include "color.hpp"
#include "models/sphere.hpp"
#include "objects/collider.hpp"

Sun::Sun() {
    _pModel = std::make_unique<Sphere>(_pTransform.get(), _pSelectionCollider->getCollidedProperty(), color::yellow);

    // Initialize Temperature Property
    _pTemperature               = new Property<int>();
    _propertyMap["Temperature"] = _pTemperature;

    _pGuiBinding = std::make_unique<GuiBinding>(this);

    // Update GUI when Property changes
    _pTemperature->set(6000);
}

Sun::~Sun() {
    // _propertyMap contains reference to this pointer, but will go out of scope when this
    // destructor is called so it can be safely deleted
    delete _pTemperature;
}

void Sun::update(int t) {
}
