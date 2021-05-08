#pragma once

#include "engine/components/gui_component.hpp"

namespace Engine::Components::Gui {
    class SunGui : public GuiComponent {
      public:
        explicit SunGui(Entity& entity)
              : GuiComponent{entity, "Sun GUI"} {};
        ~SunGui() override = default;

        auto render() -> void override;
    };
}