#pragma once

#include "engine/guibinding/guibinding.hpp"
#include "engine/objects/sun.hpp"

class SunGui : public GuiBinding {
  public:
    SunGui(const Sun* pSun);

    virtual void render(bool selected) const;

  private:
    const Sun* _pSun;
};