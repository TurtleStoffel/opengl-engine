#include "object.hpp"

#include "collider.hpp"

Object::Object() {
    _pTransform         = std::make_unique<Transform>();
    _pSelectionCollider = std::make_unique<Collider>(_pTransform.get());

    // Add callback when selection state changes
    _pSelectionCollider->getCollidedProperty()->addCallback(
        std::bind(&Object::_changeSelected, this, std::placeholders::_1));
}

void Object::render() const {
    _pModel->render();
}

bool Object::intersect(glm::vec3 rayPosition, glm::vec3 rayDirection) const {
    return _pSelectionCollider->intersect(rayPosition, rayDirection);
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
