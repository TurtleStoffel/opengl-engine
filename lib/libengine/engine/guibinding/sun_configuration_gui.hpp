#pragma once

#include "engine/guibinding/guibinding.hpp"

class Sun;

class SunConfigurationGui : public GuiBinding {
  public:
    SunConfigurationGui(Sun& pSun);

    auto render() const -> void override;

  private:
    Sun& m_sun;
};