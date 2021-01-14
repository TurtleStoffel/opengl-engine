#pragma once

class ShaderContainer;

class Effect {
  public:
    virtual ~Effect() = default;

    virtual auto render(const ShaderContainer& shaderContainer) const -> void = 0;
};