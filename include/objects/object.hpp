#ifndef OBJECT_HPP
#define OBJECT_HPP

#include <glm/glm.hpp>
#include <map>
#include <memory>

#include "guibinding/guibinding.hpp"
#include "interfaces/updateable.hpp"
#include "models/model.hpp"
#include "objects/transform.hpp"
#include "property.hpp"

// Forward Declaration to prevent Circular Imports
class Collider;

class Object : public Updateable {
   public:
    Object();
    virtual ~Object();

    virtual void update(int t) = 0;

    std::map<std::string, AbstractProperty*> getPropertyMap();

   protected:
    /**
     * This method is automatically executed when the selected state of the object has changed.
     */
    virtual void _changeSelected(bool selected);

    /**
     * Object is responsible to add its own model to the scene
     * (game objects without models are possible)
     */
    Model* _pModel;

    /**
     * Object has the local transform (even though it is used by the Model) because an object needs
     * a notion of where it is even when it has no model (e.g. only load model when objects will be
     * visible)
     */
    Transform* _pTransform;

    /**
     * Collider is responsible to check if an object has been selected
     */
    std::unique_ptr<Collider> _pSelectionCollider;

    /**
     * Every Property on an object that can be rendered in the GUI should be registered in this map.
     */
    std::map<std::string, AbstractProperty*> _propertyMap;

    /**
     * GUI Representation of the object, belongs uniquely to the instance of this Object
     */
    std::unique_ptr<GuiBinding> _pGuiBinding;
};

#endif
