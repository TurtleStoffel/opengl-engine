#pragma once

#include "engine/components/gui_component.hpp"

namespace Engine::Components::Gui {
    class PlanetGui : public GuiComponent {
      public:
        explicit PlanetGui(Entity& entity)
              : GuiComponent{entity, "Planet GUI"} {};
        ~PlanetGui() override = default;

        auto render() -> void override;
    };
}