#include "engine/components/effect.hpp"

#include <utility>

namespace Engine::Components {
    Effect::Effect(Entity& entity)
          : Component{entity, "Effect"} {
    }

    auto Effect::renderPreRenderEffects(const ShaderRegistry& shaderRegistry) const -> void {
        for (auto& effect : m_preRenderEffects) {
            effect->render(shaderRegistry);
        }
    }

    auto Effect::renderPostRenderEffects(const ShaderRegistry& shaderRegistry) const -> void {
        for (auto& effect : m_postRenderEffects) {
            effect->render(shaderRegistry);
        }
    }

    auto Effect::addPreRenderEffect(std::unique_ptr<Effect> effect) -> void {
        m_preRenderEffects.push_back(std::move(effect));
    }

    auto Effect::addPostRenderEffect(std::unique_ptr<Effect> effect) -> void {
        m_postRenderEffects.push_back(std::move(effect));
    }

    auto Effect::render([[maybe_unused]] const ShaderRegistry& shaderRegistry) const -> void {
    }
}