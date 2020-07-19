#include "planet_gui.hpp"

PlanetGui::PlanetGui(const Planet* pPlanet) {
    _pPlanet = pPlanet;
}

void PlanetGui::render(bool selected) const {
    if (selected) {
        ImGui::SetNextWindowSize(ImVec2(200.0f, 80.0f));
        ImGui::Begin("Planet");
        ImGui::Columns(2);

        ImGui::Text("Inhabitants");
        ImGui::NextColumn();
        ImGui::Text("%d", _pPlanet->_inhabitants);
        ImGui::NextColumn();

        ImGui::Text("Ownership");
        ImGui::NextColumn();
        ImGui::Text("%.2f", _pPlanet->_ownership);
        ImGui::NextColumn();

        ImGui::Columns(1);
        ImGui::End();
    }
}