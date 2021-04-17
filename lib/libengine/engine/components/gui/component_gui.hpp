#pragma once

#include "engine/components/gui_component.hpp"

namespace Engine::Components::Gui {
    class ComponentGui : public GuiComponent {
      public:
        ComponentGui(Entity& object);
        ~ComponentGui() override = default;

        auto render() -> void override;
    };
}