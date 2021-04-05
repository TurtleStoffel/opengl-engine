#include "engine/components/gui/component_gui.hpp"

#include "engine/objects/object.hpp"

#include "imgui.h"

namespace Engine::Components::Gui {
    ComponentGui::ComponentGui(Object& object)
          : GuiComponent{object} {};

    auto ComponentGui::render() -> void {
        ImGui::Begin("Entity Component GUI");
        for (auto iterator = m_object.m_components.begin(); iterator != m_object.m_components.end();
             ++iterator) {
            // Ignore this component in the list to avoid recursive call
            if (iterator->second.get() != this) {
                iterator->second->render();
            }
        }
        ImGui::End();
    }
}