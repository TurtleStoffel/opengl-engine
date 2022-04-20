#pragma once

#include "engine/components/component.hpp"
#include "engine/components/effect.hpp"

#include <memory>

namespace Engine::Components {
    class EffectContainer : public Component {
      public:
        EffectContainer(Entity& entity);
        ~EffectContainer() override = default;

        auto addEffect(std::unique_ptr<Effect> effect) -> void;
        auto renderEffects() const -> void;

      private:
        std::vector<std::unique_ptr<Effect>> m_effects;
    };
}