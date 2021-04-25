#include "engine/components/gui/sun_gui.hpp"

#include "engine/components/collider.hpp"
#include "engine/objects/sun.hpp"

#include "imgui.h"

namespace Engine::Components::Gui {
    auto SunGui::render() -> void {
        auto& sun = static_cast<Sun&>(m_entity);

        auto collider = sun.get<Engine::Components::Collider>();
        if (collider && collider->getSelected()) {
            ImGui::SetNextWindowSize(ImVec2(200.0f, 80.0f));
            ImGui::Begin("Sun");
            ImGui::Columns(2);

            ImGui::Text("Temperature");
            ImGui::NextColumn();
            ImGui::Text("%d", sun.m_temperature);
            ImGui::NextColumn();

            ImGui::Columns(1);
            ImGui::End();
        }
    }
}