#include "engine/components/scripts/planet_rotation.hpp"

#include "engine/objects/planet.hpp"

#include <glm/glm.hpp>
#include <math.h>

namespace Engine::Components::Scripts {
    auto PlanetRotation::execute(int dt) -> void {
        auto& planet = static_cast<Planet&>(m_object);

        planet.m_rotationAngle += planet.m_rotationalSpeed * dt;
        auto transform = planet.get<Transform>();
        assert(transform);
        transform->setRelativePosition(glm::vec3{planet.m_distance * sin(planet.m_rotationAngle),
                                                 planet.m_distance * cos(planet.m_rotationAngle),
                                                 0.0f});
    }
}