#include "object.hpp"

#include "collider.hpp"

Object::Object() {
    _pTransform         = new Transform();
    _pSelectionCollider = std::make_unique<Collider>(_pTransform);

    // Add callback when selection state changes
    _pSelectionCollider->getCollidedProperty()->addCallback(
        std::bind(&Object::_changeSelected, this, std::placeholders::_1));
}

Object::~Object() {
    delete _pTransform;
}

const std::map<std::string, AbstractProperty*> Object::getPropertyMap() const {
    return _propertyMap;
}

void Object::_changeSelected(bool selected) {
    // Only update GuiBinding if it has been initialized
    if (_pGuiBinding) {
        _pGuiBinding->changeSelected(selected);
    }
}
