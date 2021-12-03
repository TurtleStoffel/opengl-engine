#include "engine/entity/entity.hpp"

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