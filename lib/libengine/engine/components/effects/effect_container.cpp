#include "engine/components/effects/effect_container.hpp"

#include <utility>

namespace Engine::Components {
    EffectContainer::EffectContainer(Entity& entity)
          : Component{entity, "Effect Container"} {
    }

    auto EffectContainer::addEffect(std::unique_ptr<Effect> effect) -> void {
        m_effects.push_back(std::move(effect));
    }

    auto EffectContainer::renderEffects() const -> void {
        for (const auto& effect : m_effects) {
            effect->render();
        }
    }
}