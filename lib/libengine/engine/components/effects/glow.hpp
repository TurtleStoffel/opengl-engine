#pragma once

#include "engine/components/effect.hpp"
#include "engine/entities/entity.hpp"
#include "engine/shaders/glow.hpp"

namespace Engine::Components::Effects {
    class Glow final : public Effect {
      public:
        Glow(Entity& entity, Shaders::Registry& shaderRegistry);
        ~Glow() override = default;

        auto render() const -> void override;

      private:
        Shaders::Glow& m_glowShader;
    };
}