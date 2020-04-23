#ifndef SUN_HPP
#define SUN_HPP

#include "objects/object.hpp"

#include "guibinding/guibinding.hpp"
#include "property.hpp"

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

#endif
