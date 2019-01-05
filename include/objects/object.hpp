#ifndef OBJECT_HPP
#define OBJECT_HPP

#include <glm/glm.hpp>

#include "interfaces/updateable.hpp"
#include "models/model.hpp"
#include "objects/transform.hpp"

class Object : public Updateable {
   public:
    Object();
    virtual ~Object();

    // Updateable interface
    virtual void update(int t) = 0;

   protected:
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
};

#endif
