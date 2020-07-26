#include "object.hpp"

#include "collider.hpp"

Object::Object() : Object(nullptr) {
}

Object::Object(Object* parent) {
    if (parent) {
        transform = std::make_unique<Transform>(parent->transform.get());
    } else {
        transform = std::make_unique<Transform>();
    }

    _pSelectionCollider = std::make_unique<Collider>(transform.get());
}

void Object::render() const {
    if (model) {
        model->render(_selected);
    }
    for (const std::unique_ptr<Object>& child : children) {
        child->render();
    }

    if (guiBinding) {
        guiBinding->render(_selected);
    }
}

bool Object::intersect(glm::vec3 rayPosition, glm::vec3 rayDirection) {
    _selected = _pSelectionCollider->intersect(rayPosition, rayDirection);
    return _selected;
}