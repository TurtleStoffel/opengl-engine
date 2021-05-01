#include "engine/objects/entity.hpp"

#include "engine/components/collider.hpp"
#include "engine/components/gui_component.hpp"
#include "engine/components/script.hpp"

namespace Engine {
    Entity::Entity(const Entity* parent, std::string name)
          : TreeNode{parent}
          , m_name{name} {
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
        auto model = get<Components::Model>();
        if (model) {
            getRequired<Components::Transform>().passModelMatrixToShader(shaderContainer);
            model->render(shaderContainer);
        }
        for (const auto& child : m_children) {
            child->render(shaderContainer);
        }

        auto guiComponent = get<Components::GuiComponent>();
        if (guiComponent) {
            guiComponent->render();
        }
    }

    auto Entity::getName() const -> const std::string& {
        return m_name;
    }

    auto Entity::visitImpl(std::function<void(const Entity&)> callback) const -> void {
        callback(*this);
    }

    auto Entity::visitImpl(std::function<void(Entity&)> callback) -> void {
        callback(*this);
    }
}