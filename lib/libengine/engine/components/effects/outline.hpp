#pragma once

#include "engine/components/effect.hpp"
#include "engine/entities/entity.hpp"
#include "engine/shaders/silhouette.hpp"

namespace Engine::Components::Effects {
    class Outline final : public Effect {
      public:
        Outline(Entity& entity, Shaders::Registry& shaderRegistry);
        ~Outline() override = default;

        auto render() const -> void override;

      private:
        Shaders::Silhouette& m_silhouetteShader;
    };
}