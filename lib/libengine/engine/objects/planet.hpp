#pragma once

#include "engine/objects/object.hpp"

class Planet : public Object {
    friend class PlanetGui;

  public:
    Planet(float distance, float radius);

    virtual void update(int dt);

  private:
    float _rotationalSpeed;

    int _inhabitants = 5000;
    float _ownership = 0.0f;
};