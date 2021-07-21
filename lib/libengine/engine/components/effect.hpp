#pragma once

#include "engine/components/component.hpp"

class ShaderRegistry;

namespace Engine {
    class Entity;
}

namespace Engine::Components {
    class Effect : public Component {
      public:
        Effect(Entity& entity)
              : Component{entity, "Effect"} {};
        ~Effect() override = default;

        virtual auto render(const ShaderRegistry& shaderRegistry) const -> void = 0;
    };
}