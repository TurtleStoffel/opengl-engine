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
    Model* _pModel;
};

#endif
