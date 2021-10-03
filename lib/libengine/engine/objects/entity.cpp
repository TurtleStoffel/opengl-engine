#include "engine/objects/entity.hpp"

#include "engine/components/collider.hpp"
#include "engine/components/effect.hpp"
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

    void Entity::render(const ShaderRegistry& shaderRegistry) const {
        auto effect = get<Components::Effect>();
        if (effect) {
            getRequired<Components::Transform>().passModelMatrixToShader(shaderRegistry);
            effect->renderPreRenderEffects(shaderRegistry);
        }
        auto model = get<Components::Model>();
        if (model) {
            getRequired<Components::Transform>().passModelMatrixToShader(shaderRegistry);
            model->render();
        }
        if (effect) {
            effect->renderPostRenderEffects(shaderRegistry);
        }
        for (const auto& child : m_children) {
            child->render(shaderRegistry);
        }

        auto guiComponent = get<Components::GuiComponent>();
        if (guiComponent) {
            guiComponent->render();
        }
    }

    auto Entity::getName() const -> const std::string& {
        return m_name;
    }

    auto Entity::getComponents() const
        -> const std::unordered_map<std::size_t, std::unique_ptr<Components::Component>>& {
        return m_components;
    }

    auto Entity::visitImpl(std::function<void(const Entity&)> callback) const -> void {
        callback(*this);
    }

    auto Entity::visitImpl(std::function<void(Entity&)> callback) -> void {
        callback(*this);
    }
}