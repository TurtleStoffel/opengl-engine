#include "object.hpp"

#include "collider.hpp"

Object::Object() {
    _pTransform         = std::make_unique<Transform>();
    _pSelectionCollider = std::make_unique<Collider>(_pTransform.get());
}

void Object::render() const {
    _pModel->render();
    if(_pSelectionCollider->getCollidedProperty()->value()) {
        _pGuiBinding->render();
    }
}

bool Object::intersect(glm::vec3 rayPosition, glm::vec3 rayDirection) const {
    return _pSelectionCollider->intersect(rayPosition, rayDirection);
}

const std::map<std::string, AbstractProperty*> Object::getPropertyMap() const {
    return _propertyMap;
}