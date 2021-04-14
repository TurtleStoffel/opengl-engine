#include "engine/components/scripts/demo_rotation.hpp"

#include "engine/objects/object.hpp"
#include "engine/objects/transform.hpp"

namespace Engine::Components::Scripts {
    auto DemoRotation::execute(int dt) -> void {
        auto rotation = m_object.m_transform->getRotation();
        rotation += glm::vec3{0.0001f * dt, 0.0f, 0.0f};
        m_object.m_transform->setRotation(rotation);
    }
}