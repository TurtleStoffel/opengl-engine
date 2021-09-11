#pragma once

#include "engine/components/component.hpp"

namespace Engine::Components {
    class StarState final : public Component {
      public:
        StarState(Entity& entity)
              : Component{entity, "Star State"} {};
        ~StarState() override = default;

        // Temperature in Kelvin
        int m_temperature = 6000;
    };
}