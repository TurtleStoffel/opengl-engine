#include "objects/object.hpp"

Object::Object() {
    _pTransform = new Transform();

    // Register changelister to _selected Property
    _selected.addCallback(std::bind(&Object::_changeSelected, this, std::placeholders::_1));
}

Object::~Object() {
    delete _pTransform;
}

std::map<std::string, std::string> Object::getPropertyMap() {
    return _propertyMap;
}

void Object::_changeSelected(bool selected) {
}
