#include "objects/object.hpp"

Object::Object() {
    _pTransform = new Transform();

    _selected = new Property<bool>();
    // Register changelister to _selected Property
    _selected->addCallback(std::bind(&Object::_changeSelected, this, std::placeholders::_1));
}

Object::~Object() {
    delete _pTransform;
}

std::map<std::string, AbstractProperty*> Object::getPropertyMap() {
    return _propertyMap;
}

void Object::_changeSelected(bool selected) {
    // Only update GuiBinding if it has been initialized
    if (_pGuiBinding) {
        _pGuiBinding->changeSelected(selected);
    }
}
