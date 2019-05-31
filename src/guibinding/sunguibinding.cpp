#include "guibinding/sunguibinding.hpp"

#include "application.hpp"
#include "objects/sun.hpp"

SunGuiBinding::SunGuiBinding(Object* pObject) : GuiBinding(pObject) {
    _pPanel->setMinHeight(50);
    _pPanel->setMinWidth(100);

    // Setup the textfield representing the Temperature
    _pTemperatureText = new gui::TextField();

    // Add temperature field to the panel
    _pPanel->addChild(_pTemperatureText);

    render();
}

void SunGuiBinding::render() {
    std::map<std::string, std::string> propertyMap = _pObject->getPropertyMap();
    _pTemperatureText->setContent("Temperature\t" + propertyMap["Temperature"]);
}
