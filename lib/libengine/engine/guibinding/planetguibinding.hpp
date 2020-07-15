#pragma once

#include "guibinding/guibinding.hpp"
#include "objects/planet.hpp"

class PlanetGuiBinding : public GuiBinding {
  public:
    PlanetGuiBinding(const Planet* pPlanet);

    virtual void render() const;

  private:
    const Planet* _pPlanet;
};