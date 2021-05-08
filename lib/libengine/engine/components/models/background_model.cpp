#include "engine/components/models/background_model.hpp"

namespace Engine::Components::Models {
    BackgroundModel::BackgroundModel(Entity& entity)
          : Model{entity, "Background Model"} {
    }

    auto BackgroundModel::generateImpl() -> void {
        Vertex vertex;
        vertex.position = glm::vec3(-1.0f, 1.0f, 0.0f);
        m_vertices.push_back(vertex);
        vertex.position = glm::vec3(1.0f, 1.0f, 0.0f);
        m_vertices.push_back(vertex);
        vertex.position = glm::vec3(-1.0f, -1.0f, 0.0f);
        m_vertices.push_back(vertex);
        vertex.position = glm::vec3(1.0f, -1.0f, 0.0f);
        m_vertices.push_back(vertex);

        m_indices.push_back(0);
        m_indices.push_back(3);
        m_indices.push_back(1);
        m_indices.push_back(0);
        m_indices.push_back(2);
        m_indices.push_back(3);
    }
}