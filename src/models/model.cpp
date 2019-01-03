#include "models/model.hpp"

#include <glm/gtc/matrix_transform.hpp>

#include "opengl.hpp"
#include "shadercontainer.hpp"

Model::Model() {
    // Generate OpenGL buffers
    glGenVertexArrays(1, &_vao);
    glGenBuffers(1, &_vbo);
}

Model::~Model() {
    // Empty virtual destructor
}

void Model::render() {
    // Calculate model transformation matrix
    glm::mat4 modelMatrix = glm::rotate(glm::mat4(1.0f), _rotation, glm::vec3(0.0f, 0.0f, 1.0f));
    modelMatrix           = glm::scale(modelMatrix, _scale);
    modelMatrix           = glm::translate(modelMatrix, _position);

    // Apply model transformation matrix
    ShaderContainer::instance()->setModelViewProjectionMatrix(&modelMatrix[0][0], nullptr, nullptr);

    // Bind vertex data of current model
    glBindVertexArray(_vao);

    // Render silhouette if object is selected
    if (_selected) {
        ShaderContainer::silhouetteShader()->use();
        glDrawArrays(GL_TRIANGLES, 0, _vertices.size());
    }

    // Render object itself
    ShaderContainer::lowPolyShader()->use();
    glDrawArrays(GL_TRIANGLES, 0, _vertices.size());
}

void Model::setSelected(bool selected) {
    _selected = selected;
}

void Model::scale(glm::vec3 v) {
    _scale *= v;
}

void Model::translate(glm::vec3 v) {
    _position += v;
}

void Model::rotate(float degrees) {
    _rotation += degrees;
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
    // clang-format off
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)offsetof(Vertex, normal));
    glEnableVertexAttribArray(1);
    // clang-format on
    glVertexAttribPointer(2, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)offsetof(Vertex, color));
    glEnableVertexAttribArray(2);

    glBindVertexArray(0);
}
