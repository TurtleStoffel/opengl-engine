#pragma once

#include "engine/components/models/vector.hpp"
#include "engine/models/effects/effect.hpp"

#include <list>

namespace Engine {
    class Entity;
}

class DebugVectors : public Effect {
  public:
    DebugVectors(Engine::Entity& object);
    ~DebugVectors() override = default;

    auto render(const ShaderRegistry& shaderContainer) const -> void override;

  private:
    std::list<std::unique_ptr<Engine::Components::Models::Vector>> m_vectors;
};