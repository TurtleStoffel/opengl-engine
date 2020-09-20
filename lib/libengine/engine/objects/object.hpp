#pragma once

#include <glm/glm.hpp>
#include <map>
#include <memory>

#include "guibinding/guibinding.hpp"
#include "models/model.hpp"
#include "objects/collider.hpp"
#include "objects/transform.hpp"

class ShaderContainer;

class Object {
  public:
    Object() : Object(nullptr){};
    Object(const Object* parent);

    virtual ~Object() = default;

    virtual void update([[maybe_unused]] int t){};

    virtual void render(const ShaderContainer& shaderContainer) const;
    bool intersect(glm::vec3 rayPosition, glm::vec3 rayDirection);

  protected:
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
    bool _selected = false;

    std::unique_ptr<GuiBinding> guiBinding;

    std::vector<std::unique_ptr<Object>> children;
};