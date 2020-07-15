#pragma once

#include "guibinding/guibinding.hpp"
#include "objects/sun.hpp"

class SunGuiBinding : public GuiBinding {
  public:
    SunGuiBinding(const Sun* pSun);

    virtual void render() const;

  private:
    const Sun* _pSun;
};