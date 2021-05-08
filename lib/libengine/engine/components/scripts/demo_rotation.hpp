#pragma once

#include "engine/components/script.hpp"

namespace Engine::Components::Scripts {
    class DemoRotation : public Script {
      public:
        DemoRotation(Entity& entity)
              : Script{entity, "Demo Rotation Script"} {};
        ~DemoRotation() override = default;

        auto execute(int dt) -> void override;
    };
}