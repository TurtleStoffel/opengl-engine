#pragma once

#include "models/effects/effect.hpp"

class Glow final : public Effect {
  public:
    using Effect::Effect;

    ~Glow() = default;

    void render(bool selected, const ShaderContainer& shaderContainer) const override;
};