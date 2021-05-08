#pragma once

#include "engine/components/script.hpp"

namespace Engine::Components::Scripts {
    class PlanetRotation : public Script {
      public:
        PlanetRotation(Entity& entity)
              : Script{entity, "Planet Rotation Script"} {};
        ~PlanetRotation() override = default;

        auto execute(int dt) -> void override;
    };
}