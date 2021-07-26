#include "engine/components/gui/sun_gui.hpp"

#include "engine/components/collider.hpp"
#include "engine/components/state/sun_state.hpp"
#include "engine/objects/entity.hpp"

#include "imgui.h"

namespace Engine::Components::Gui {
    auto SunGui::render() -> void {
        auto collider = m_entity.get<Collider>();
        if (collider && collider->getSelected()) {
            auto& sunState = m_entity.getRequired<SunState>();

            ImGui::SetNextWindowSize(ImVec2(200.0f, 80.0f));
            ImGui::Begin("Sun");
            ImGui::Columns(2);

            ImGui::Text("Temperature");
            ImGui::NextColumn();
            ImGui::Text("%d", sunState.m_temperature);
            ImGui::NextColumn();

            ImGui::Columns(1);
            ImGui::End();
        }
    }
}