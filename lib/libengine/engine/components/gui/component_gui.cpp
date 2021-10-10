#include "engine/components/gui/component_gui.hpp"

#include "engine/entity/entity.hpp"

#include "imgui.h"

namespace Engine::Components::Gui {
    ComponentGui::ComponentGui(Entity& entity)
          : GuiComponent{entity, "Component GUI"} {};

    auto ComponentGui::render() -> void {
        auto& components = m_entity.getComponents();

        ImGui::Begin("Entity Component GUI");
        for (auto iterator = components.begin(); iterator != components.end(); ++iterator) {
            // Ignore this component in the list to avoid recursive call
            if (iterator->second.get() != this) {
                iterator->second->renderConfiguration();
                ImGui::Separator();
            }
        }
        ImGui::End();
    }
}