#pragma once

#include "engine/components/effect.hpp"

namespace Engine {
    class Entity;
}

namespace Engine::Components::Effects {
    class Outline final : public Effect {
      public:
        Outline(Entity& entity);
        ~Outline() override = default;

        auto render(const ShaderRegistry& shaderRegistry) const -> void override;
    };
}