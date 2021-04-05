#pragma once

#include "engine/components/script.hpp"

namespace Engine::Components::Scripts {
    class PlanetRotation : public Script {
      public:
        PlanetRotation(Object& object)
              : Script{object} {};
        ~PlanetRotation() override = default;

        auto execute(int dt) -> void override;

        auto render() -> void override{};
    };
}