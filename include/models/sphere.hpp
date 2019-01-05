#ifndef SPHERE_HPP
#define SPHERE_HPP

#include "models/model.hpp"

struct Face {
    Vertex v1;
    Vertex v2;
    Vertex v3;
};

class Sphere : public Model {
   public:
    Sphere(Transform* pTransform);
    Sphere(Transform* pTransform, int depth);
    Sphere(Transform* pTransform, glm::vec3 (*colorGenerator)());
    Sphere(Transform* pTransform, int depth, glm::vec3 (*colorGenerator)());

    virtual bool intersect(glm::vec3 rayPosition, glm::vec3 rayDirection);

   private:
    Vertex _getMidpoint(Vertex p1, Vertex p2, glm::vec3 color);
    Vertex _createVertex(glm::vec3 point, glm::vec3 color);
};

#endif
