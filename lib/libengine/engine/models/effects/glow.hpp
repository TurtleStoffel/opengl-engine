#pragma once

#include "engine/components/model.hpp"

class Model;

class Glow final : public Effect {
  public:
    Glow(const Engine::Components::Model& model);
    ~Glow() override = default;

    void render(const ShaderRegistry& shaderContainer) const override;

  private:
    const Engine::Components::Model& m_model;
};