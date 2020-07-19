#pragma once

#include "imgui.h"

class GuiBinding {
  public:
    virtual ~GuiBinding(){};

    virtual void render(bool selected) const = 0;
};