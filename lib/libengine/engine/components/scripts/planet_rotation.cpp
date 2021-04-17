#include "engine/components/scripts/planet_rotation.hpp"

#include "engine/objects/planet.hpp"

#include <glm/glm.hpp>
#include <math.h>

namespace Engine::Components::Scripts {
    auto PlanetRotation::execute(int dt) -> void {
        auto& planet = static_cast<Planet&>(m_entity);

        planet.m_rotationAngle += planet.m_rotationalSpeed * dt;
        planet.getRequired<Transform>().setRelativePosition(
            glm::vec3{planet.m_distance * sin(planet.m_rotationAngle),
                      planet.m_distance * cos(planet.m_rotationAngle),
                      0.0f});
    }
}