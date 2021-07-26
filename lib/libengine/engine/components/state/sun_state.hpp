#pragma once

#include "engine/components/component.hpp"

namespace Engine::Components {
    class SunState final : public Component {
      public:
        SunState(Entity& entity)
              : Component{entity, "Sun State"} {};
        ~SunState() override = default;

        // Temperature in Kelvin
        int m_temperature = 6000;
    };
}