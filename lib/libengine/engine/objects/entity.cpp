#include "engine/objects/entity.hpp"

#include "engine/components/gui_component.hpp"
#include "engine/components/script.hpp"
#include "engine/objects/collider.hpp"

namespace Engine {
    Entity::Entity(const Entity* parent, std::string name)
          : TreeNode{parent}
          , m_name{name} {

        /*
        Temporarily disabled, reintroduce when moving Collider to a Component
        Can not be refactored right now because Transform is not known at construction time
        */
        // m_selectionCollider = std::make_unique<Collider>(m_transform.get());
    }

    Entity::Entity()
          : Entity{nullptr, "Invalid Object Name"} {
    }

    auto Entity::update(int dt) -> void {
        auto updateScriptComponent = get<Components::Script>();
        if (updateScriptComponent) {
            updateScriptComponent->execute(dt);
        }
    }

    void Entity::render(const ShaderRegistry& shaderContainer) const {
        if (m_model) {
            getRequired<Components::Transform>().passModelMatrixToShader(shaderContainer);
            m_model->render(shaderContainer);
        }
        for (const auto& child : m_children) {
            child->render(shaderContainer);
        }

        if (m_guiBinding) {
            m_guiBinding->render();
        }
        auto guiComponent = get<Components::GuiComponent>();
        if (guiComponent) {
            guiComponent->render();
        }
    }

    bool Entity::intersect(glm::vec3 rayPosition, glm::vec3 rayDirection) {
        if (m_selectionCollider) {
            m_selected = m_selectionCollider->intersect(rayPosition, rayDirection);
        } else {
            m_selected = false;
        }
        return m_selected;
    }

    auto Entity::getName() const -> const std::string& {
        return m_name;
    }

    auto Entity::getSelected() const -> bool {
        return m_selected;
    }

    auto Entity::visitImpl(std::function<void(const Entity&)> callback) const -> void {
        callback(*this);
    }

    auto Entity::visitImpl(std::function<void(Entity&)> callback) -> void {
        callback(*this);
    }
}