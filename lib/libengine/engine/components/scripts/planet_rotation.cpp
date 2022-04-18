#include "engine/components/scripts/planet_rotation.hpp"

#include "engine/components/state/planet_state.hpp"
#include "engine/entities/entity.hpp"

#include <glm/glm.hpp>
#include <math.h>

namespace Engine::Components::Scripts {
    auto PlanetRotation::execute(int dt) -> void {
        auto& planetState = m_entity.getRequired<PlanetState>();

        planetState.m_rotationAngle += planetState.m_rotationalSpeed * dt;
        m_entity.getRequired<Transform>().setRelativePosition(
            glm::vec3{planetState.m_distance * sin(planetState.m_rotationAngle),
                      planetState.m_distance * cos(planetState.m_rotationAngle),
                      0.0f});
    }
}