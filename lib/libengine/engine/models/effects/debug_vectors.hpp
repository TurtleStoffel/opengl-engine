#pragma once

#include "effect.hpp"
#include "models/vector.hpp"

#include <list>

class DebugVectors : public Effect {
  public:
    DebugVectors(const Model& model);
    ~DebugVectors() override = default;

    auto render(bool selected, const ShaderContainer& shaderContainer) const -> void override;

  private:
    std::list<Vector> m_vectors;
};