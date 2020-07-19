#include "gui_factory.hpp"

#include "planet_gui.hpp"
#include "sun_configuration_gui.hpp"
#include "sun_gui.hpp"

GuiFactory::GuiFactory(GuiType guiType) {
    this->guiType = guiType;
}

std::unique_ptr<GuiBinding> GuiFactory::createSunGui(Sun* sun) {
    if (guiType == GAME) {
        return std::make_unique<SunGui>(sun);
    } else {
        return std::make_unique<SunConfigurationGui>(sun);
    }
}

std::unique_ptr<GuiBinding> GuiFactory::createPlanetGui(Planet* planet) {
    if (guiType == GAME) {
        return std::make_unique<PlanetGui>(planet);
    } else {
        return std::make_unique<PlanetGui>(planet);
    }
}