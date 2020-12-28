#pragma once

#include "engine/models/effects/effect.hpp"

class Model;

class Outline final : public Effect {
  public:
    Outline(const Model& model);
    ~Outline() override = default;

    void render(bool selected, const ShaderContainer& shaderContainer) const override;

  private:
    const Model& m_model;
};