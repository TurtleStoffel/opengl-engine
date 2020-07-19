#pragma once

#include <memory>

#include "guibinding.hpp"
#include "objects/planet.hpp"
#include "objects/sun.hpp"

class GuiFactory {
  public:
    enum GuiType { CONFIGURATION, GAME };

    GuiFactory(GuiType guiType = GAME);

    std::unique_ptr<GuiBinding> createSunGui(Sun* sun);
    std::unique_ptr<GuiBinding> createPlanetGui(Planet* planet);

  protected:
    GuiType guiType;
};