#pragma once

#include "engine/models/model.hpp"

class Model;

class Glow final : public Effect {
  public:
    Glow(const Model& model);
    ~Glow() override = default;

    void render(const ShaderRegistry& shaderContainer) const override;

  private:
    const Model& m_model;
};