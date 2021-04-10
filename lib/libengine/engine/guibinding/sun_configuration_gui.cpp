#include "sun_configuration_gui.hpp"

#include "engine/objects/sun.hpp"

SunConfigurationGui::SunConfigurationGui(Sun& sun)
      : m_sun{sun} {
}

auto SunConfigurationGui::render() const -> void {
    ImGui::Begin("Sun Configuration");
    if (ImGui::SliderInt("Temperature", &m_sun.m_temperature, 3190, 17000)) {
        m_sun._generateModel();
    }
    ImGui::End();
}