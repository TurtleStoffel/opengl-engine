#ifndef OBJECT_HPP
#define OBJECT_HPP

#include <glm/glm.hpp>

#include "interfaces/transformable.hpp"
#include "interfaces/updateable.hpp"

#include "models/model.hpp"

class Object : public Transformable, public Updateable {
   public:
    virtual ~Object();

    // Transformable interface
    virtual void scale(glm::vec3 v);
    virtual void translate(glm::vec3 v);
    virtual void rotate(float degrees);

    // Updateable interface
    virtual void update(int t) = 0;

   protected:
    /**
     * Every Object is responsible to add its own model to the scene
     * (game objects without models are possible)
     */
    Model* _pModel;
};

#endif
