#include "sun_gui.hpp"

SunGui::SunGui(const Sun* pSun) {
    _pSun = pSun;
}

void SunGui::render(bool selected) const {
    if (selected) {
        ImGui::SetNextWindowSize(ImVec2(200.0f, 80.0f));
        ImGui::Begin("Sun");
        ImGui::Columns(2);

        ImGui::Text("Temperature");
        ImGui::NextColumn();
        ImGui::Text("%d", _pSun->_temperature);
        ImGui::NextColumn();

        ImGui::Columns(1);
        ImGui::End();
    }
}