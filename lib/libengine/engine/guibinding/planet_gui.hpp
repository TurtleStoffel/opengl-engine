#pragma once

#include "engine/guibinding/guibinding.hpp"

class Planet;

class PlanetGui final : public GuiBinding {
  public:
    PlanetGui(const Planet& planet);
    ~PlanetGui() override = default;

    auto render() const -> void override;

  private:
    const Planet& m_planet;
};