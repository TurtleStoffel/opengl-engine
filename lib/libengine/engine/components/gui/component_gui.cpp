#include "engine/components/gui/component_gui.hpp"

#include "imgui.h"

namespace Engine::Components::Gui {
    ComponentGui::ComponentGui(Object& object)
          : GuiComponent{object} {};

    auto ComponentGui::render() -> void {
        ImGui::Begin("Entity Component GUI");
        ImGui::End();
    }
}