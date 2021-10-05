#include "engine/components/effect.hpp"

#include <utility>

namespace Engine::Components {
    Effect::Effect(Entity& entity)
          : Component{entity, "Effect"} {
    }

    auto Effect::addEffect(std::unique_ptr<Effect> effect) -> void {
        m_effects.push_back(std::move(effect));
    }

    auto Effect::renderEffects(const ShaderRegistry& shaderRegistry) const -> void {
        for (auto& effect : m_effects) {
            effect->render(shaderRegistry);
        }
    }

    auto Effect::render([[maybe_unused]] const ShaderRegistry& shaderRegistry) const -> void {
    }
}