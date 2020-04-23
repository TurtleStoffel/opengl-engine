#ifndef PLANET_HPP
#define PLANET_HPP

#include "objects/object.hpp"

class Planet : public Object {
   public:
    Planet(float distance, float radius);
    ~Planet();

    // Updateable interface
    virtual void update(int t);

   private:
    float _rotationalSpeed;
};

#endif
