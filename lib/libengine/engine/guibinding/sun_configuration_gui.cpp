#include "sun_configuration_gui.hpp"

SunConfigurationGui::SunConfigurationGui(Sun* pSun) {
    _pSun = pSun;
}

void SunConfigurationGui::render(bool selected __attribute__((unused))) const {
    ImGui::Begin("Sun Configuration");
    if (ImGui::SliderInt("Temperature", &_pSun->_temperature, 3190, 17000)) {
        _pSun->_generateModel();
    }
    ImGui::End();
}