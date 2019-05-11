#ifndef SUN_HPP
#define SUN_HPP

#include "objects/object.hpp"

#include "guibinding/sunguibinding.hpp"
#include "property.hpp"
#include "scene.hpp"

class Sun : public Object {
    friend class SunGuiBinding;

   public:
    Sun(Scene* pScene);
    ~Sun();

    // Updateable interface
    virtual void update(int t);

   private:
    // Temperature in Kelvin
    Property<int> _temperature;

    // GUI representation of the Object is defined in the GUI binding
    SunGuiBinding* _pGuiBinding;
};

#endif
