#pragma once

#include "engine/components/collider.hpp"
#include "engine/components/component.hpp"
#include "engine/components/model.hpp"
#include "engine/components/transform.hpp"
#include "engine/tree.hpp"

#include <glm/glm.hpp>
#include <memory>
#include <stdexcept>
#include <string>
#include <unordered_map>
#include <utility>

class ShaderRegistry;

namespace Engine {
    class Entity final : public TreeNode<Entity> {
      public:
        explicit Entity(const Entity* parent, std::string name);
        explicit Entity();
        ~Entity() override = default;

        auto update(int dt) -> void;

        auto getName() const -> const std::string&;
        auto getComponents() const
            -> const std::unordered_map<std::size_t, std::unique_ptr<Components::Component>>&;

        template <typename TComponentType>
        auto registerComponent(std::unique_ptr<TComponentType> component) -> void;
        template <typename TComponentType, typename... TArgs>
        auto createAndRegisterComponent(TArgs&&... args) -> void;

        template <typename TComponentType>
        auto get() const -> TComponentType*;
        template <typename TComponentType>
        auto getRequired() const -> TComponentType&;

      protected:
        auto visitImpl(std::function<void(const Entity&)> callback) const -> void override;
        auto visitImpl(std::function<void(Entity&)> callback) -> void override;

        std::unordered_map<std::size_t, std::unique_ptr<Components::Component>> m_components;

        std::string m_name = "Invalid Entity Name";
    };

    template <typename TComponentType>
    auto Entity::registerComponent(std::unique_ptr<TComponentType> component) -> void {
        auto componentHash = typeid(TComponentType).hash_code();

        auto iterator = m_components.find(componentHash);
        // Each type of component can only be registered once
        assert(iterator == m_components.end());

        m_components.insert({componentHash, std::move(component)});
    }

    template <typename TComponentType, typename... TArgs>
    auto Entity::createAndRegisterComponent(TArgs&&... args) -> void {
        registerComponent<TComponentType>(
            std::make_unique<TComponentType>(std::forward<TArgs>(args)...));
    }

    template <typename TComponentType>
    auto Entity::get() const -> TComponentType* {
        auto iterator = m_components.find(typeid(TComponentType).hash_code());
        if (iterator == m_components.end()) {
            return nullptr;
        }

        return static_cast<TComponentType*>(iterator->second.get());
    }

    template <typename TComponentType>
    auto Entity::getRequired() const -> TComponentType& {
        auto componentPtr = get<TComponentType>();
        assert(componentPtr);
        return *componentPtr;
    }
}