#include "engine/models/settlement_model.hpp"

#include "engine/color.hpp"

#include <math.h>

SettlementModel::SettlementModel(Transform* transform) : Model(*transform) {
    Vertex vertex;
    vertex.position = glm::vec3(-0.5f, 0.5f, 0.0f);
    vertex.color    = color::black;
    m_vertices.push_back(vertex);
    vertex.position = glm::vec3(0.5f, 0.5f, 0.0f);
    vertex.color    = color::black;
    m_vertices.push_back(vertex);
    vertex.position = glm::vec3(-0.5f, -0.5f, 0.0f);
    vertex.color    = color::black;
    m_vertices.push_back(vertex);
    vertex.position = glm::vec3(0.5f, -0.5f, 0.0f);
    vertex.color    = color::black;
    m_vertices.push_back(vertex);

    m_indices.push_back(0);
    m_indices.push_back(3);
    m_indices.push_back(1);
    m_indices.push_back(0);
    m_indices.push_back(2);
    m_indices.push_back(3);

    _setupBuffers();
}