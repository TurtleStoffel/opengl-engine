#pragma once

#include "object.hpp"

class Sun : public Object {
    friend class SunGuiBinding;

  public:
    Sun();

    // Updateable interface
    virtual void update(int t);

  private:
    // Temperature in Kelvin
    float _temperature = 6000;
};