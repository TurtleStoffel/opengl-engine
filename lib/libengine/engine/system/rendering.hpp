#pragma once

#include "engine/entity/entity.hpp"
#include "engine/shaderregistry.hpp"

#include <set>

namespace Engine::System {
    /**
     * Each entity must be unregistered in the render system before being destructed
     */
    class Rendering final {
      public:
        explicit Rendering(ShaderRegistry& shaderRegistry);

        auto render() const -> void;

        auto registerEntity(Entity* entity) -> void;
        auto unregisterEntity(Entity* entity) -> void;

      private:
        std::set<Entity*> m_entities;
        ShaderRegistry& m_shaderRegistry;
    };
}