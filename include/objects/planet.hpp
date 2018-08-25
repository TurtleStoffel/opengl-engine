#ifndef PLANET_HPP
#define PLANET_HPP

#include "scene.hpp"

#include "objects/object.hpp"

class Planet : public Object {
   public:
    Planet(Scene* pScene);
    ~Planet();

    // Updateable interface
    virtual void update(int t);
};

#endif
