#pragma once

#include "engine/entities/entity.hpp"
#include "engine/shaders/registry.hpp"

#include <set>

namespace Engine::Systems {
    /**
     * Each entity must be unregistered in the render system before being destructed
     */
    class Rendering final {
      public:
        explicit Rendering(Shaders::Registry& shaderRegistry);

        auto render() const -> void;

        auto registerEntity(Entity* entity) -> void;
        auto unregisterEntity(Entity* entity) -> void;

      private:
        std::set<Entity*> m_entities;
        Shaders::Registry& m_shaderRegistry;
    };
}