#include "objects/object.hpp"

Object::Object() {
    _pTransform = new Transform();
}

Object::~Object() {
    delete _pTransform;
}
