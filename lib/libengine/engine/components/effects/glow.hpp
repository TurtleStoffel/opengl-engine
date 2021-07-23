#pragma once

#include "engine/components/effect.hpp"

namespace Engine {
    class Entity;
}

namespace Engine::Components::Effects {
    class Glow final : public Effect {
      public:
        Glow(Entity& entity);
        ~Glow() override = default;

        auto render(const ShaderRegistry& shaderRegistry) const -> void override;
    };
}