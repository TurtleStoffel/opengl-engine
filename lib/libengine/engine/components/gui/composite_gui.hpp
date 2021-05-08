#pragma once

#include "engine/components/gui_component.hpp"

#include <memory>
#include <vector>

namespace Engine::Components::Gui {
    class CompositeGui : public GuiComponent {
      public:
        CompositeGui(Entity& entity)
              : GuiComponent{entity, "Composite GUI"} {};
        ~CompositeGui() override = default;

        auto render() -> void override;
        auto addSubcomponent(std::unique_ptr<GuiComponent> subcomponent) -> void override;

      private:
        std::vector<std::unique_ptr<GuiComponent>> m_subcomponents;
    };
}