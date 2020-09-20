#pragma once

#include "models/model.hpp"
#include "opengl.hpp"

class Effect {
  public:
    Effect(const Model& model) : model(model){};

    virtual ~Effect() = default;

    virtual void render(bool selected, const ShaderContainer& shaderContainer) const = 0;

  protected:
    const Model& model;
};