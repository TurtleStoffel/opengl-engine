#pragma once

#include "engine/objects/object.hpp"

class Planet : public Object {
    friend class PlanetGui;

  public:
    Planet(float distance, float radius);

    virtual void update(int dt);

  private:
    float m_rotationalSpeed;
    float m_rotationAngle;
    float m_distance;

    int m_inhabitants = 5000;
    float m_ownership = 0.0f;
};