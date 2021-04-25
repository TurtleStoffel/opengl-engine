#pragma once

#include "engine/components/script.hpp"

namespace Engine::Components::Scripts {
    class DemoRotation : public Script {
      public:
        DemoRotation(Entity& object)
              : Script{object} {};
        ~DemoRotation() override = default;

        auto execute(int dt) -> void override;
    };
}