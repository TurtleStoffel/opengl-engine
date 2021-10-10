#pragma once

#include "engine/components/component.hpp"
#include "engine/shaderregistry.hpp"

#include <memory>
#include <vector>

namespace Engine {
    class Entity;
}

namespace Engine::Components {
    class Effect : public Component {
      public:
        Effect(Entity& entity);
        ~Effect() override = default;

        auto addEffect(std::unique_ptr<Effect> effect) -> void;
        auto renderEffects(ShaderRegistry& shaderRegistry) const -> void;

      protected:
        virtual auto render(ShaderRegistry& shaderRegistry) const -> void;

      private:
        std::vector<std::unique_ptr<Effect>> m_effects;
    };
}