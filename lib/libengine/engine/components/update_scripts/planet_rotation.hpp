#pragma once

#include "engine/components/update_scripts/update_script.hpp"

namespace Engine::Components::UpdateScripts {
    class PlanetRotation : public UpdateScript {
      public:
        PlanetRotation(Object& object)
              : UpdateScript{object} {};
        ~PlanetRotation() override = default;

        auto update(int dt) -> void override;
    };
}