#pragma once

#include "engine/guibinding/guibinding.hpp"

class Sun;

class SunGui : public GuiBinding {
  public:
    SunGui(const Sun& sun);

    auto render() const -> void override;

  private:
    const Sun& m_sun;
};