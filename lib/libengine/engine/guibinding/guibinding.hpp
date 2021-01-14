#pragma once

#include "imgui.h"

class GuiBinding {
  public:
    virtual ~GuiBinding() = default;

    virtual auto render() const -> void = 0;
};