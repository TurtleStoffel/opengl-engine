#pragma once

#include "engine/components/component.hpp"
#include "engine/shaders/registry.hpp"

#include <memory>
#include <vector>

namespace Engine {
    class Entity;
}

namespace Engine::Components {
    /**
     * Effects are expected to store all their requirements for rendering in their state (e.g.,
     * Shaders)
     */
    class Effect : public Component {
      public:
        Effect(Entity& entity);
        ~Effect() override = default;

        virtual auto render() const -> void = 0;
    };
}