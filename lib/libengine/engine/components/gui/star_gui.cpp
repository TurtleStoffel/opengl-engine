#include "engine/components/gui/star_gui.hpp"

#include "engine/components/collider.hpp"
#include "engine/components/state/star_state.hpp"
#include "engine/objects/entity.hpp"

#include "imgui.h"

namespace Engine::Components::Gui {
    auto StarGui::render() -> void {
        auto collider = m_entity.get<Collider>();
        if (collider && collider->getSelected()) {
            auto& starState = m_entity.getRequired<StarState>();

            ImGui::SetNextWindowSize(ImVec2(200.0f, 80.0f));
            ImGui::Begin("Star");
            ImGui::Columns(2);

            ImGui::Text("Temperature");
            ImGui::NextColumn();
            ImGui::Text("%d", starState.m_temperature);
            ImGui::NextColumn();

            ImGui::Columns(1);
            ImGui::End();
        }
    }
}