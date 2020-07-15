#include "sunguibinding.hpp"

#include "imgui.h"

SunGuiBinding::SunGuiBinding(const Sun* pSun) {
    _pSun = pSun;
}

void SunGuiBinding::render() const {
    ImGui::SetNextWindowSize(ImVec2(200.0f, 80.0f));
    ImGui::Begin("Sun");
    ImGui::Columns(2);

    ImGui::Text("Temperature");
    ImGui::NextColumn();
    ImGui::Text("%.2f", _pSun->_temperature);
    ImGui::NextColumn();

    ImGui::Columns(1);
    ImGui::End();
}