#pragma once

#include "engine/components/component.hpp"

namespace Engine::Components {
    class PlanetState final : public Component {
      public:
        PlanetState(Entity& entity)
              : Component{entity, "Planet State"} {};
        ~PlanetState() override = default;

        float m_rotationalSpeed;
        float m_rotationAngle;
        float m_distance;

        int m_inhabitants = 5000;
        float m_ownership = 0.0f;
    };
}