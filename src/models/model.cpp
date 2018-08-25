#include "models/model.hpp"

#include <glm/gtc/matrix_transform.hpp>

#include "opengl.hpp"

Model::Model() {
    // Generate OpenGL buffers
    glGenVertexArrays(1, &_vao);
    glGenBuffers(1, &_vbo);

    // Get uniform location for model matrix
    GLint shader;
    glGetIntegerv(GL_CURRENT_PROGRAM, &shader);
    _modelMatrixUniform = glGetUniformLocation(shader, "model");
}

Model::~Model() {
    // Empty virtual destructor
}

void Model::render() {
    // Apply model transformation matrix
    glm::mat4 modelMatrix = glm::scale(glm::mat4(1.0f), _scale);
    modelMatrix           = glm::translate(modelMatrix, _position);
    glUniformMatrix4fv(_modelMatrixUniform, 1, GL_FALSE, &modelMatrix[0][0]);

    // Render vertices
    glBindVertexArray(_vao);
    glDrawArrays(GL_TRIANGLES, 0, _vertices.size());
}

void Model::scale(glm::vec3 v) {
    _scale *= v;
}

void Model::translate(glm::vec3 v) {
    _position += v;
}

void Model::rotate(glm::vec3 v) {
    _rotation += v;
}

void Model::_setupBuffers() {
    // Enable model VAO and VBO
    glBindVertexArray(_vao);
    glBindBuffer(GL_ARRAY_BUFFER, _vbo);
    // Upload data
    glBufferData(GL_ARRAY_BUFFER, _vertices.size() * sizeof(Vertex), &_vertices[0], GL_STATIC_DRAW);

    // Get attribute information from vertices
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)0);
    glEnableVertexAttribArray(0);
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)offsetof(Vertex, color));
    glEnableVertexAttribArray(1);

    glBindVertexArray(0);
}
