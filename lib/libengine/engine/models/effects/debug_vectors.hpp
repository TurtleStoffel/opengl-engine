#pragma once

#include "engine/models/effects/effect.hpp"
#include "engine/models/vector.hpp"

#include <list>

class DebugVectors : public Effect {
  public:
    DebugVectors(const Object& object);
    ~DebugVectors() override = default;

    auto render(const ShaderRegistry& shaderContainer) const -> void override;

  private:
    std::list<std::unique_ptr<Vector>> m_vectors;
};