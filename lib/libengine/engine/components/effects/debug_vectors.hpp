#pragma once

#include "engine/components/effect.hpp"
#include "engine/components/models/vector.hpp"

#include <list>

namespace Engine {
    class Entity;
}

namespace Engine::Components::Effects {
    class DebugVectors : public Effect {
      public:
        DebugVectors(Entity& object);
        ~DebugVectors() override = default;

        auto render() const -> void override;

      private:
        std::list<std::unique_ptr<Models::Vector>> m_vectors;
    };
}