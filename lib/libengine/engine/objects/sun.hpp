#pragma once

#include "object.hpp"

class GuiFactory;

class Sun : public Object {
    friend class SunGui;
    friend class SunConfigurationGui;

  public:
    Sun(GuiFactory guiFactory);

  private:
    // Used by SunConfigurationGui
    void _generateModel();

    // Temperature in Kelvin
    int _temperature = 6000;
};