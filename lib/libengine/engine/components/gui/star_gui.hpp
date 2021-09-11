#pragma once

#include "engine/components/gui_component.hpp"

namespace Engine::Components::Gui {
    class StarGui : public GuiComponent {
      public:
        explicit StarGui(Entity& entity)
              : GuiComponent{entity, "Star GUI"} {};
        ~StarGui() override = default;

        auto render() -> void override;
    };
}