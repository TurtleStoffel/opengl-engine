#pragma once

#include "engine/objects/entity.hpp"

#include <memory>

namespace Engine::Components::Gui {
    class PlanetGui;
}

namespace Engine::Components::Scripts {
    class PlanetRotation;
}

class ShaderRegistry;

namespace Engine {
    class Planet : public Entity {
        friend class Components::Gui::PlanetGui;
        friend class Components::Scripts::PlanetRotation;

      public:
        static auto createDefault(float distance, float radius,
                                  const ShaderRegistry& shaderRegistry) -> std::unique_ptr<Planet>;

        Planet(float distance);
        ~Planet() override = default;

      private:
        float m_rotationalSpeed;
        float m_rotationAngle;
        float m_distance;

        int m_inhabitants = 5000;
        float m_ownership = 0.0f;
    };
}