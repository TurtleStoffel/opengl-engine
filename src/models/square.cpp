#include <glm/glm.hpp>

#include "models/square.hpp"

Square::Square() {
    Vertex vertex;
    vertex.position = glm::vec3(-0.5f, 0.5f, 0.0f);
    vertex.color = glm::vec3(0.0f, 1.0f, 0.0f);
    _vertices.push_back(vertex);
    vertex.position = glm::vec3(0.5f, 0.5f, 0.0f);
    vertex.color = glm::vec3(0.0f, 1.0f, 0.0f);
    _vertices.push_back(vertex);
    vertex.position = glm::vec3(-0.5f, -0.5f, 0.0f);
    vertex.color = glm::vec3(0.0f, 1.0f, 0.0f);
    _vertices.push_back(vertex);


    vertex.position = glm::vec3(-0.5f, -0.5f, 0.0f);
    vertex.color = glm::vec3(0.0f, 1.0f, 1.0f);
    _vertices.push_back(vertex);
    vertex.position = glm::vec3(0.5f, 0.5f, 0.0f);
    vertex.color = glm::vec3(0.0f, 1.0f, 1.0f);
    _vertices.push_back(vertex);
    vertex.position = glm::vec3(0.5f, -0.5f, 0.0f);
    vertex.color = glm::vec3(0.0f, 1.0f, 1.0f);
    _vertices.push_back(vertex);

    _setupBuffers();

    //glBindVertexArray(_vao);
    //glBindBuffer(GL_ARRAY_BUFFER, _vbo);
    //glBufferData(GL_ARRAY_BUFFER, _vertices.size() * sizeof(Vertex), &_vertices[0], GL_STATIC_DRAW);

    //glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)0);
    //glEnableVertexAttribArray(0);
    //glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)offsetof(Vertex, color));
    //glEnableVertexAttribArray(1);

    //glBindVertexArray(0);
}
