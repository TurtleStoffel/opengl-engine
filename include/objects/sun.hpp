#ifndef SUN_HPP
#define SUN_HPP

#include "objects/object.hpp"

#include "guibinding/sunguibinding.hpp"
#include "property.hpp"
#include "scene.hpp"

class Sun : public Object {
   public:
    Sun(Scene* pScene);
    ~Sun();

    // Updateable interface
    virtual void update(int t);

   private:
    // Temperature in Kelvin
    Property<int> _temperature;
};

#endif
