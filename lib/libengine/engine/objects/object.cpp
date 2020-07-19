#include "object.hpp"

#include "collider.hpp"

Object::Object() {
    _pTransform         = std::make_unique<Transform>();
    _pSelectionCollider = std::make_unique<Collider>(_pTransform.get());
}

void Object::render() const {
    _pModel->render(_selected);
    _pGuiBinding->render(_selected);
}

bool Object::intersect(glm::vec3 rayPosition, glm::vec3 rayDirection) {
    _selected = _pSelectionCollider->intersect(rayPosition, rayDirection);
    return _selected;
}