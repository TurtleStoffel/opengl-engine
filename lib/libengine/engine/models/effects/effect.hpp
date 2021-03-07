#pragma once

class ShaderRegistry;

class Effect {
  public:
    virtual ~Effect() = default;

    virtual auto render(const ShaderRegistry& shaderContainer) const -> void = 0;
};