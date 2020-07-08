#pragma once

#include <glm/glm.hpp>
#include <map>
#include <memory>

#include "guibinding/guibinding.hpp"
#include "interfaces/updateable.hpp"
#include "models/model.hpp"
#include "objects/transform.hpp"
#include "objects/collider.hpp"

#include "util/property.hpp"

class Object : public Updateable {
  public:
    Object();
    virtual ~Object() {};

    virtual void update(int t) = 0;

    void render() const;
    bool intersect(glm::vec3 rayPosition, glm::vec3 rayDirection) const;

    const std::map<std::string, AbstractProperty*> getPropertyMap() const;

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

    /**
     * Every Property on an object that can be rendered in the GUI should be registered in this map.
     */
    std::map<std::string, AbstractProperty*> _propertyMap;

    /**
     * GUI Representation of the object
     */
    std::unique_ptr<GuiBinding> _pGuiBinding;
};