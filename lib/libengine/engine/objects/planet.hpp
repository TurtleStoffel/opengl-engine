#pragma once

#include "engine/objects/object.hpp"

namespace Engine::Components::Scripts {
    class PlanetRotation;
}

class Planet : public Object {
    friend class PlanetGui;
    friend class Engine::Components::Scripts::PlanetRotation;

  public:
    Planet(float distance, float radius);

  private:
    float m_rotationalSpeed;
    float m_rotationAngle;
    float m_distance;

    int m_inhabitants = 5000;
    float m_ownership = 0.0f;
};