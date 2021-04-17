#pragma once

#include "engine/components/component.hpp"
#include "engine/components/transform.hpp"
#include "engine/guibinding/guibinding.hpp"
#include "engine/models/model.hpp"
#include "engine/objects/collider.hpp"
#include "engine/tree.hpp"

#include <glm/glm.hpp>
#include <memory>
#include <stdexcept>
#include <string>
#include <unordered_map>
#include <utility>

namespace Engine::Components::Gui {
    class ComponentGui;
}

namespace Engine::Components::Scripts {
    class DemoRotation;
}

class ShaderRegistry;

namespace Engine {
    class Entity : public TreeNode<Entity> {
        friend class Components::Gui::ComponentGui;
        friend class Components::Scripts::DemoRotation;

      public:
        explicit Entity(const Entity* parent, std::string name);
        explicit Entity();
        ~Entity() override = default;

        auto update(int dt) -> void;

        void render(const ShaderRegistry& shaderContainer) const;
        bool intersect(glm::vec3 rayPosition, glm::vec3 rayDirection);

        auto getName() const -> const std::string&;
        auto getSelected() const -> bool;

        template <typename TComponentType>
        auto registerComponent(std::unique_ptr<TComponentType> component) -> void;
        template <typename TComponentType>
        auto get() const -> TComponentType*;

      protected:
        auto visitImpl(std::function<void(const Entity&)> callback) const -> void override;
        auto visitImpl(std::function<void(Entity&)> callback) -> void override;

        std::unordered_map<std::size_t, std::unique_ptr<Components::Component>> m_components;

        std::unique_ptr<Model> m_model;

        /**
         * Collider is responsible to check if an object has been selected
         */
        std::unique_ptr<Collider> m_selectionCollider;
        bool m_selected = false;

        std::unique_ptr<GuiBinding> m_guiBinding;

        std::string m_name = "Invalid Entity Name";
    };

    template <typename TComponentType>
    auto Entity::registerComponent(std::unique_ptr<TComponentType> component) -> void {
        m_components.insert({typeid(TComponentType).hash_code(), std::move(component)});
    }

    template <typename TComponentType>
    auto Entity::get() const -> TComponentType* {
        auto iterator = m_components.find(typeid(TComponentType).hash_code());
        if (iterator == m_components.end()) {
            return nullptr;
        }

        return static_cast<TComponentType*>(iterator->second.get());
    }
}