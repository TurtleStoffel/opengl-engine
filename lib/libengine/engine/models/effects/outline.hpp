#pragma once

#include "engine/models/effects/effect.hpp"

class Model;

class Outline final : public Effect {
  public:
    Outline(const Model& model);
    ~Outline() override = default;

    void render(const ShaderRegistry& shaderContainer) const override;

  private:
    const Model& m_model;
};