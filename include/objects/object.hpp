#ifndef OBJECT_HPP
#define OBJECT_HPP

#include <glm/glm.hpp>

#include "interfaces/transformable.hpp"

#include "models/model.hpp"

class Object : public Transformable {
   public:
    virtual ~Object();

    virtual void scale(glm::vec3 v);
    virtual void translate(glm::vec3 v);
    virtual void rotate(glm::vec3 v);

   protected:
    /**
     * Every Object is responsible to add its own model to the scene
     * (game objects without models are possible)
     */
    Model* _pModel;
};

#endif
