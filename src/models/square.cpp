#include <glm/glm.hpp>

#include "models/square.hpp"

Square::Square(Transform* pTransform, Property<bool>* selected) : Model(pTransform, selected) {
    Vertex vertex;
    vertex.position = glm::vec3(-0.5f, 0.5f, 0.0f);
    vertex.color    = glm::vec3(0.0f, 1.0f, 0.0f);
    _vertices.push_back(vertex);
    vertex.position = glm::vec3(0.5f, 0.5f, 0.0f);
    vertex.color    = glm::vec3(0.0f, 1.0f, 0.0f);
    _vertices.push_back(vertex);
    vertex.position = glm::vec3(-0.5f, -0.5f, 0.0f);
    vertex.color    = glm::vec3(0.0f, 1.0f, 0.0f);
    _vertices.push_back(vertex);

    vertex.position = glm::vec3(-0.5f, -0.5f, 0.0f);
    vertex.color    = glm::vec3(0.0f, 1.0f, 1.0f);
    _vertices.push_back(vertex);
    vertex.position = glm::vec3(0.5f, 0.5f, 0.0f);
    vertex.color    = glm::vec3(0.0f, 1.0f, 1.0f);
    _vertices.push_back(vertex);
    vertex.position = glm::vec3(0.5f, -0.5f, 0.0f);
    vertex.color    = glm::vec3(0.0f, 1.0f, 1.0f);
    _vertices.push_back(vertex);

    _setupBuffers();
}