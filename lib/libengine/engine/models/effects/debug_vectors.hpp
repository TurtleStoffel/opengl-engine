#pragma once

#include "engine/models/effects/effect.hpp"
#include "engine/models/vector.hpp"

#include <list>

class DebugVectors : public Effect {
  public:
    DebugVectors(const Model& model);
    ~DebugVectors() override = default;

    auto render(bool selected, const ShaderContainer& shaderContainer) const -> void override;

  private:
    std::list<std::unique_ptr<Vector>> m_vectors;
};