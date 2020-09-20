#pragma once

#include "models/effects/effect.hpp"

class Outline final : public Effect {
  public:
    using Effect::Effect;

    ~Outline() = default;

    void render(bool selected, const ShaderContainer& shaderContainer) const override;
};