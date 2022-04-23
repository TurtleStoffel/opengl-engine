#include "models/triangle.hpp"

#include "engine/entities/entity.hpp"

#include <string>

#include <glm/glm.hpp>

namespace ModelEditor::Models {
    Triangle::Triangle(Engine::Entity& entity)
          : Engine::Components::Model{entity, "Triangle"} {
    }

    auto Triangle::generateImpl() -> void {
        m_vertices.emplace_back(Vertex{glm::vec3{0.0f, 1.0f, 0.0f},
                                       glm::vec3{0.0f, 0.0f, 1.0f},
                                       glm::vec3{1.0f, 1.0f, 1.0f}});
        m_indices.push_back(0);
        m_vertices.emplace_back(Vertex{glm::vec3{-0.5f, -0.5f, 0.0f},
                                       glm::vec3{0.0f, 0.0f, 1.0f},
                                       glm::vec3{1.0f, 1.0f, 1.0f}});
        m_indices.push_back(1);
        m_vertices.emplace_back(Vertex{glm::vec3{0.5f, -0.5f, 0.0f},
                                       glm::vec3{0.0f, 0.0f, 1.0f},
                                       glm::vec3{1.0f, 1.0f, 1.0f}});
        m_indices.push_back(2);
    }
}