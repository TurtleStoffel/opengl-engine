#include "sun_gui.hpp"

#include "engine/objects/sun.hpp"

SunGui::SunGui(const Sun& sun) : m_sun{sun} {
}

auto SunGui::render() const -> void {
    if (m_sun.getSelected()) {
        ImGui::SetNextWindowSize(ImVec2(200.0f, 80.0f));
        ImGui::Begin("Sun");
        ImGui::Columns(2);

        ImGui::Text("Temperature");
        ImGui::NextColumn();
        ImGui::Text("%d", m_sun._temperature);
        ImGui::NextColumn();

        ImGui::Columns(1);
        ImGui::End();
    }
}