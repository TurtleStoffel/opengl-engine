#ifndef PLANET_HPP
#define PLANET_HPP

#include "scene.hpp"

#include "objects/object.hpp"

class Planet : public Object {
   public:
    Planet(Scene* pScene);
    ~Planet();
};

#endif
