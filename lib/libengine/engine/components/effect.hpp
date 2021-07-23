#pragma once

#include "engine/components/component.hpp"

#include <memory>
#include <vector>

class ShaderRegistry;

namespace Engine {
    class Entity;
}

namespace Engine::Components {
    class Effect : public Component {
      public:
        Effect(Entity& entity);
        ~Effect() override = default;

        auto renderPreRenderEffects(const ShaderRegistry& shaderRegistry) const -> void;
        auto renderPostRenderEffects(const ShaderRegistry& shaderRegistry) const -> void;

        auto addPreRenderEffect(std::unique_ptr<Effect> effect) -> void;
        auto addPostRenderEffect(std::unique_ptr<Effect> effect) -> void;

      protected:
        virtual auto render(const ShaderRegistry& shaderRegistry) const -> void;

      private:
        std::vector<std::unique_ptr<Effect>> m_preRenderEffects;
        std::vector<std::unique_ptr<Effect>> m_postRenderEffects;
    };
}