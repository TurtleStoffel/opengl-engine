#include "engine/models/background_model.hpp"

#include "engine/color.hpp"
#include "engine/models/model.hpp"

#include <math.h>

BackgroundModel::BackgroundModel(const Object& object) : Model{object} {
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