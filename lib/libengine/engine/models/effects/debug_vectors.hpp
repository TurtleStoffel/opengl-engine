#pragma once

#include "engine/models/effects/effect.hpp"
#include "engine/models/vector.hpp"

#include <list>

namespace Engine {
    class Object;
}

class DebugVectors : public Effect {
  public:
    DebugVectors(const Engine::Object& object);
    ~DebugVectors() override = default;

    auto render(const ShaderRegistry& shaderContainer) const -> void override;

  private:
    std::list<std::unique_ptr<Vector>> m_vectors;
};