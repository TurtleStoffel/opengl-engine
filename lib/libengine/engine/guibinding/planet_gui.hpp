#pragma once

#include "guibinding/guibinding.hpp"
#include "objects/planet.hpp"

class PlanetGui : public GuiBinding {
  public:
    PlanetGui(const Planet* pPlanet);

    virtual void render(bool selected) const;

  private:
    const Planet* _pPlanet;
};