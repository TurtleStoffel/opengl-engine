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

        auto render(Shaders::Registry& shaderRegistry) const -> void override;
    };
}