#pragma once

#include "object.hpp"

#include "guibinding/guibinding.hpp"

#include "util/property.hpp"

class Sun : public Object {
  public:
    Sun();
    ~Sun();

    // Updateable interface
    virtual void update(int t);

  private:
    // Temperature in Kelvin
    Property<int>* _pTemperature;
};