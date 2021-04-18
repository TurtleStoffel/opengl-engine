#include "planet_gui.hpp"

#include "engine/components/collider.hpp"
#include "engine/objects/planet.hpp"

PlanetGui::PlanetGui(const Planet& planet)
      : m_planet{planet} {
}

auto PlanetGui::render() const -> void {
    auto collider = m_planet.get<Engine::Components::Collider>();
    if (collider && collider->getSelected()) {
        ImGui::SetNextWindowSize(ImVec2(200.0f, 80.0f));
        ImGui::Begin("Planet");
        ImGui::Columns(2);

        ImGui::Text("Inhabitants");
        ImGui::NextColumn();
        ImGui::Text("%d", m_planet.m_inhabitants);
        ImGui::NextColumn();

        ImGui::Text("Ownership");
        ImGui::NextColumn();
        ImGui::Text("%.2f", m_planet.m_ownership);
        ImGui::NextColumn();

        ImGui::Columns(1);
        ImGui::End();
    }
}