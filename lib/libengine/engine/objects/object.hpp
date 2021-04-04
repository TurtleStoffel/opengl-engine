#pragma once

#include "engine/components/component.hpp"
#include "engine/guibinding/guibinding.hpp"
#include "engine/models/model.hpp"
#include "engine/objects/collider.hpp"
#include "engine/objects/transform.hpp"
#include "engine/tree.hpp"

#include <glm/glm.hpp>
#include <memory>
#include <stdexcept>
#include <string>
#include <unordered_map>
#include <utility>

class ShaderRegistry;

class Object : public TreeNode<Object> {
  public:
    explicit Object(const Object* parent, std::string name);
    explicit Object();
    ~Object() override = default;

    auto update(int dt) -> void;

    void render(const ShaderRegistry& shaderContainer) const;
    bool intersect(glm::vec3 rayPosition, glm::vec3 rayDirection);

    auto getName() const -> const std::string&;
    auto getTransform() const -> const Transform&;
    auto getTransform() -> Transform&;
    auto getSelected() const -> bool;

    template <typename TComponentType>
    auto registerComponent(std::unique_ptr<TComponentType> component) -> void;
    template <typename TComponentType>
    auto get() -> TComponentType*;

  protected:
    auto visitImpl(std::function<void(const Object&)> callback) const -> void override;
    auto visitImpl(std::function<void(Object&)> callback) -> void override;

    std::unordered_map<std::size_t, std::unique_ptr<Engine::Components::Component>> m_components;

    std::unique_ptr<Model> m_model;

    /**
     * Object has the local transform (even though it is used by the Model) because an object needs
     * a notion of where it is even when it has no model (e.g. only load model when objects will be
     * visible)
     */
    std::unique_ptr<Transform> m_transform;

    /**
     * Collider is responsible to check if an object has been selected
     */
    std::unique_ptr<Collider> m_selectionCollider;
    bool m_selected = false;

    std::unique_ptr<GuiBinding> m_guiBinding;

    std::string m_name = "Invalid Object Name";
};

template <typename TComponentType>
auto Object::registerComponent(std::unique_ptr<TComponentType> component) -> void {
    m_components.insert({typeid(TComponentType).hash_code(), std::move(component)});
}

template <typename TComponentType>
auto Object::get() -> TComponentType* {
    auto iterator = m_components.find(typeid(TComponentType).hash_code());
    if (iterator == m_components.end()) {
        return nullptr;
    }

    return static_cast<TComponentType*>(iterator->second.get());
}