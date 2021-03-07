#pragma once

#include "engine/guibinding/guibinding.hpp"
#include "engine/models/model.hpp"
#include "engine/objects/collider.hpp"
#include "engine/objects/transform.hpp"
#include "engine/tree.hpp"

#include <glm/glm.hpp>
#include <map>
#include <memory>
#include <string>

class ShaderRegistry;

class Object : public TreeNode<Object> {
  public:
    explicit Object(const Object* parent, std::string name);
    explicit Object();
    ~Object() override = default;

    virtual void update([[maybe_unused]] int t){};

    virtual void render(const ShaderRegistry& shaderContainer) const;
    bool intersect(glm::vec3 rayPosition, glm::vec3 rayDirection);

    auto getName() const -> const std::string&;
    auto getTransform() const -> const Transform&;
    auto getSelected() const -> bool;

  protected:
    auto visitImpl(std::function<void(const Object&)> callback) -> void override;

    std::unique_ptr<Model> model;

    /**
     * Object has the local transform (even though it is used by the Model) because an object needs
     * a notion of where it is even when it has no model (e.g. only load model when objects will be
     * visible)
     */
    std::unique_ptr<Transform> transform;

    /**
     * Collider is responsible to check if an object has been selected
     */
    std::unique_ptr<Collider> _pSelectionCollider;
    bool m_selected = false;

    std::unique_ptr<GuiBinding> guiBinding;

    std::string m_name = "Invalid Object Name";
};