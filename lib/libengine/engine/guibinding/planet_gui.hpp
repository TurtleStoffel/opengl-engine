#pragma once

#include "engine/guibinding/guibinding.hpp"
#include "engine/objects/planet.hpp"

class PlanetGui : public GuiBinding {
  public:
    PlanetGui(const Planet* pPlanet);

    virtual void render(bool selected) const;

  private:
    const Planet* _pPlanet;
};