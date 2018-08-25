#include "objects/object.hpp"

Object::~Object() {
    // Empty virtual destructor
}

void Object::scale(glm::vec3 v) {
    if (_pModel) {
        _pModel->scale(v);
    }
}

void Object::translate(glm::vec3 v) {
    if (_pModel) {
        _pModel->translate(v);
    }
}

void Object::rotate(glm::vec3 v) {
    if (_pModel) {
        _pModel->rotate(v);
    }
}
