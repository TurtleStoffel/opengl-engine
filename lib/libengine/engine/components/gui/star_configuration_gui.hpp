#pragma once

#include "engine/components/gui_component.hpp"

namespace Engine::Components::Gui {
    class StarConfigurationGui : public GuiComponent {
      public:
        explicit StarConfigurationGui(Entity& entity)
              : GuiComponent{entity, "Star Configuration GUI"} {};
        ~StarConfigurationGui() override = default;

        auto render() -> void override;
    };
}