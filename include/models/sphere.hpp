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
    Sphere();
    Sphere(int depth);

   private:
    Vertex _getMidpoint(Vertex p1, Vertex p2);
};

#endif
