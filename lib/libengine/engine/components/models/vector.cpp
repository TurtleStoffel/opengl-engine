#include "vector.hpp"

#include "engine/color.hpp"
#include "engine/entity/entity.hpp"

namespace Engine::Components::Models {
    Vector::Vector(Entity& entity, const glm::vec3& direction)
          : Model{entity, "Vector Model"}
          , m_direction{direction} {
        m_renderingMode = GL_LINES;
    }

    auto Vector::generateImpl() -> void {
        auto normalizedDirection = glm::normalize(m_direction);

        auto origin = glm::vec3{0.0f, 0.0f, 0.0f};
        m_vertices.push_back(Vertex{origin, origin, Color::blue});
        m_vertices.push_back(
            Vertex{normalizedDirection * 2.0f, normalizedDirection * 2.0f, Color::yellow});

        m_indices.push_back(0);
        m_indices.push_back(1);
    }
}