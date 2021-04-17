#include "engine/components/scripts/demo_rotation.hpp"

#include "engine/components/transform.hpp"
#include "engine/objects/entity.hpp"

namespace Engine::Components::Scripts {
    auto DemoRotation::execute(int dt) -> void {
        auto transform = m_object.get<Transform>();
        assert(transform);
        auto rotation = transform->getRotation();
        rotation += glm::vec3{0.0001f * dt, 0.0f, 0.0f};
        transform->setRotation(rotation);
    }
}