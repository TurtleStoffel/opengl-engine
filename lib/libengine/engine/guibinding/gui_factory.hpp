#pragma once

#include <memory>

#include "engine/guibinding/guibinding.hpp"
#include "engine/objects/planet.hpp"
#include "engine/objects/sun.hpp"

class GuiFactory {
  public:
    enum GuiType { CONFIGURATION, GAME };

    GuiFactory(GuiType guiType = GAME);

    std::unique_ptr<GuiBinding> createSunGui(Sun* sun);
    std::unique_ptr<GuiBinding> createPlanetGui(Planet* planet);

  protected:
    GuiType guiType;
};