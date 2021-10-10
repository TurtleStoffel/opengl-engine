#include "engine/components/effect.hpp"

#include <utility>

namespace Engine::Components {
    Effect::Effect(Entity& entity)
          : Component{entity, "Effect"} {
    }

    auto Effect::addEffect(std::unique_ptr<Effect> effect) -> void {
        m_effects.push_back(std::move(effect));
    }

    auto Effect::renderEffects(ShaderRegistry& shaderRegistry) const -> void {
        for (auto& effect : m_effects) {
            effect->render(shaderRegistry);
        }
    }

    auto Effect::render([[maybe_unused]] ShaderRegistry& shaderRegistry) const -> void {
    }
}