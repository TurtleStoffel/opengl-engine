#include "guibinding/sunguibinding.hpp"

#include "application.hpp"
#include "objects/sun.hpp"

SunGuiBinding::SunGuiBinding(Sun* pSun) {
    _pSun = pSun;

    _pPanel = new gui::Panel();
    _pPanel->setMinHeight(50);
    _pPanel->setMinWidth(100);

    // Setup the textfield representing the Temperature
    _pTemperatureText = new gui::TextField();
    _pTemperatureText->setContent("Temperature\t" + std::to_string(_pSun->_temperature.value()));

    // Add temperature field to the panel
    _pPanel->addChild(_pTemperatureText);

    // Add panel in Application GUI
    Application::instance()->getGui()->setSelectedPanel(_pPanel);

    // Make sure the GUI gets updated when the Temperature Property changes values
    _pSun->_temperature.addGenericCallback(std::bind(&SunGuiBinding::_update, this));
}

void SunGuiBinding::_update() {
    _pTemperatureText->setContent("Temperature\t" + std::to_string(_pSun->_temperature.value()));
}
