#pragma once

#include "engine/models/effects/effect.hpp"

namespace Engine::Components {
    class Model;
}

class Outline final : public Effect {
  public:
    Outline(const Engine::Components::Model& model);
    ~Outline() override = default;

    void render(const ShaderRegistry& shaderContainer) const override;

  private:
    const Engine::Components::Model& m_model;
};