#pragma once

#include <glm/glm.hpp>
#include <map>
#include <memory>

#include "guibinding/guibinding.hpp"
#include "models/model.hpp"
#include "objects/collider.hpp"
#include "objects/transform.hpp"

class Object {
  public:
    Object();
    virtual ~Object(){};

    virtual void update(int t __attribute__((unused))){};

    void render() const;
    bool intersect(glm::vec3 rayPosition, glm::vec3 rayDirection);

  protected:
    /**
     * Object is responsible to add its own model to the scene
     * (game objects without models are possible)
     */
    std::unique_ptr<Model> _pModel;

    /**
     * Object has the local transform (even though it is used by the Model) because an object needs
     * a notion of where it is even when it has no model (e.g. only load model when objects will be
     * visible)
     */
    std::unique_ptr<Transform> _pTransform;

    /**
     * Collider is responsible to check if an object has been selected
     */
    std::unique_ptr<Collider> _pSelectionCollider;
    bool _selected = false;

    /**
     * GUI Representation of the object
     */
    std::unique_ptr<GuiBinding> _pGuiBinding;
};