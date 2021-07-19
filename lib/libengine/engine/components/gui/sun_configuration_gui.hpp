#pragma once

#include "engine/components/gui_component.hpp"

namespace Engine::Components::Gui {
    class SunConfigurationGui : public GuiComponent {
      public:
        explicit SunConfigurationGui(Entity& entity)
              : GuiComponent{entity, "Sun Configuration GUI"} {};
        ~SunConfigurationGui() override = default;

        auto render() -> void override;
    };
}