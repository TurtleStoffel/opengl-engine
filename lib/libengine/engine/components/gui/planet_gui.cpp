#include "engine/components/gui/planet_gui.hpp"

#include "engine/components/collider.hpp"
#include "engine/objects/entity.hpp"
#include "engine/objects/planet.hpp"

#include "imgui.h"

namespace Engine::Components::Gui {
    auto PlanetGui::render() -> void {
        auto& planet = static_cast<Planet&>(m_entity);

        auto collider = m_entity.get<Engine::Components::Collider>();
        if (collider && collider->getSelected()) {
            ImGui::SetNextWindowSize(ImVec2(200.0f, 80.0f));
            ImGui::Begin("Planet");
            ImGui::Columns(2);

            ImGui::Text("Inhabitants");
            ImGui::NextColumn();
            ImGui::Text("%d", planet.m_inhabitants);
            ImGui::NextColumn();

            ImGui::Text("Ownership");
            ImGui::NextColumn();
            ImGui::Text("%.2f", planet.m_ownership);
            ImGui::NextColumn();

            ImGui::Columns(1);
            ImGui::End();
        }
    }
}