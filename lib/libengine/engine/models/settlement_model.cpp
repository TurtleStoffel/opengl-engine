#include "settlement_model.hpp"

#include <math.h>

#include "color.hpp"

SettlementModel::SettlementModel(Transform* transform) : Model(transform) {
    Vertex vertex;
    vertex.position = glm::vec3(-0.5f, 0.5f, 0.0f);
    vertex.color    = color::black;
    vertices.push_back(vertex);
    vertex.position = glm::vec3(0.5f, 0.5f, 0.0f);
    vertex.color    = color::black;
    vertices.push_back(vertex);
    vertex.position = glm::vec3(-0.5f, -0.5f, 0.0f);
    vertex.color    = color::black;
    vertices.push_back(vertex);
    vertex.position = glm::vec3(0.5f, -0.5f, 0.0f);
    vertex.color    = color::black;
    vertices.push_back(vertex);

    indices.push_back(0);
    indices.push_back(3);
    indices.push_back(1);
    indices.push_back(0);
    indices.push_back(2);
    indices.push_back(3);

    _setupBuffers();
}