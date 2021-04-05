#pragma once

#include "engine/objects/object.hpp"

#include <memory>

namespace Engine::Components::Scripts {
    class PlanetRotation;
}

class ShaderRegistry;

class Planet : public Engine::Object {
    friend class PlanetGui;
    friend class Engine::Components::Scripts::PlanetRotation;

  public:
    static auto createDefault(float distance, float radius, const ShaderRegistry& shaderRegistry)
        -> std::unique_ptr<Planet>;

    Planet(float distance, float radius);
    ~Planet() override = default;

  private:
    float m_rotationalSpeed;
    float m_rotationAngle;
    float m_distance;

    int m_inhabitants = 5000;
    float m_ownership = 0.0f;
};