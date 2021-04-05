#include "object.hpp"

#include "engine/components/gui_component.hpp"
#include "engine/components/script.hpp"
#include "engine/objects/collider.hpp"

Object::Object(const Object* parent, std::string name)
      : TreeNode{parent}
      , m_name{name} {
    if (parent) {
        m_transform = std::make_unique<Transform>(parent->m_transform.get());
    } else {
        m_transform = std::make_unique<Transform>();
    }

    m_selectionCollider = std::make_unique<Collider>(m_transform.get());
}

Object::Object()
      : Object{nullptr, "Invalid Object Name"} {
}

auto Object::update(int dt) -> void {
    auto updateScriptComponent = get<Engine::Components::Script>();
    if (updateScriptComponent) {
        updateScriptComponent->execute(dt);
    }
}

void Object::render(const ShaderRegistry& shaderContainer) const {
    if (m_model) {
        m_transform->passModelMatrixToShader(shaderContainer);
        m_model->render(shaderContainer);
    }
    for (const auto& child : m_children) {
        child->render(shaderContainer);
    }

    if (m_guiBinding) {
        m_guiBinding->render();
    }
    auto guiComponent = get<Engine::Components::GuiComponent>();
    if (guiComponent) {
        guiComponent->render();
    }
}

bool Object::intersect(glm::vec3 rayPosition, glm::vec3 rayDirection) {
    m_selected = m_selectionCollider->intersect(rayPosition, rayDirection);
    return m_selected;
}

auto Object::getName() const -> const std::string& {
    return m_name;
}

auto Object::getTransform() const -> const Transform& {
    return *m_transform.get();
}

auto Object::getTransform() -> Transform& {
    return *m_transform.get();
}

auto Object::getSelected() const -> bool {
    return m_selected;
}

auto Object::visitImpl(std::function<void(const Object&)> callback) const -> void {
    callback(*this);
}

auto Object::visitImpl(std::function<void(Object&)> callback) -> void {
    callback(*this);
}