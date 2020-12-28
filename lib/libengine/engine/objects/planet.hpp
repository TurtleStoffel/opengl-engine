#pragma once

#include "engine/objects/object.hpp"
#include "engine/objects/settlement.hpp"

class Planet : public Object {
    friend class PlanetGui;

  public:
    Planet(float distance, float radius);

    virtual void update(int dt);

  private:
    std::vector<std::unique_ptr<Settlement>> settlements;
    float _rotationalSpeed;

    int _inhabitants = 5000;
    float _ownership = 0.0f;
};