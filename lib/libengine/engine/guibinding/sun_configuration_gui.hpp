#pragma once

#include "guibinding/guibinding.hpp"
#include "objects/sun.hpp"

class SunConfigurationGui : public GuiBinding {
  public:
    SunConfigurationGui(Sun* pSun);

    virtual void render(bool selected) const;

  private:
    Sun* _pSun;
};