#pragma once

#include "engine/opengl.hpp"

class ShaderContainer;

class Effect {
  public:
    virtual ~Effect() = default;

    virtual auto render(bool selected, const ShaderContainer& shaderContainer) const -> void = 0;
};