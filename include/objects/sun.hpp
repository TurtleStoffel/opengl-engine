#ifndef SUN_HPP
#define SUN_HPP

#include "scene.hpp"

#include "objects/object.hpp"

class Sun : public Object {
   public:
    Sun(Scene* pScene);
    ~Sun();

    // Updateable interface
    virtual void update(int t);
};

#endif
