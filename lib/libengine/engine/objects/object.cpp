#include "object.hpp"

#include "collider.hpp"

Object::Object(const Object* parent, std::string name) : TreeNode{parent}, m_name{name} {
    if (parent) {
        transform = std::make_unique<Transform>(parent->transform.get());
    } else {
        transform = std::make_unique<Transform>();
    }

    _pSelectionCollider = std::make_unique<Collider>(transform.get());
}

Object::Object() : Object{nullptr, "Invalid Object Name"} {
}

void Object::render(const ShaderContainer& shaderContainer) const {
    if (model) {
        model->render(_selected, shaderContainer);
    }
    for (const auto& child : m_children) {
        child->render(shaderContainer);
    }

    if (guiBinding) {
        guiBinding->render(_selected);
    }
}

bool Object::intersect(glm::vec3 rayPosition, glm::vec3 rayDirection) {
    _selected = _pSelectionCollider->intersect(rayPosition, rayDirection);
    return _selected;
}

auto Object::getName() const -> const std::string& {
    return m_name;
}

auto Object::getTransform() const -> const Transform& {
    return *transform.get();
}

auto Object::visitImpl(std::function<void(const Object&)> callback) -> void {
    callback(*this);
}