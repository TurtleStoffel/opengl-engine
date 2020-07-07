#pragma once

#include "object.hpp"

class Planet : public Object {
  public:
    Planet(float distance, float radius);

    // Updateable interface
    virtual void update(int t);

  private:
    float _rotationalSpeed;

    Property<int>* _pInhabitants;
    Property<float>* _pOwnership;
};