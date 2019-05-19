#ifndef OBJECT_HPP
#define OBJECT_HPP

#include <glm/glm.hpp>
#include <map>

#include "interfaces/updateable.hpp"
#include "models/model.hpp"
#include "objects/transform.hpp"
#include "property.hpp"

class Object : public Updateable {
   public:
    Object();
    virtual ~Object();

    virtual void update(int t) = 0;

    std::map<std::string, std::string> getPropertyMap();

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
     * Property representing if the object has been selected or not. Is passed to the Model of the
     * object and a change to this value automatically calls _changeSelected.
     */
    Property<bool> _selected;

    /**
     * Every Property on an object that can be rendered in the GUI should be registered in this map.
     */
    std::map<std::string, std::string> _propertyMap;
};

#endif
