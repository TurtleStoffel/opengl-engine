#pragma once

#include "object.hpp"

class Planet : public Object {
    friend class PlanetGuiBinding;

  public:
    Planet(float distance, float radius);

    // Updateable interface
    virtual void update(int t);

  private:
    float _rotationalSpeed;

    int _inhabitants = 5000;
    float _ownership = 0.0f;
};