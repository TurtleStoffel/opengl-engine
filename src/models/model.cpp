#include "models/model.hpp"

#include <glm/gtc/matrix_transform.hpp>

#include "opengl.hpp"
#include "shadercontainer.hpp"

Model::Model(Transform* pTransform, Property<bool>* selected) {
    _pTransform = pTransform;
    _selected   = selected;

    // Generate OpenGL buffers
    glGenVertexArrays(1, &_vao);
    glGenBuffers(1, &_vbo);
    glGenBuffers(1, &_ebo);
}

Model::Model(Transform* pTransform) : Model(pTransform, nullptr) {
    // Constructor Overload
}

Model::Model() : Model(nullptr, nullptr) {
    // Constructor Overload
}

Model::~Model() {
    // Empty virtual destructor
}

void Model::render() {
    // Set Model Matrix in Shader
    _pTransform->passModelMatrixToShader();

    // Bind vertex data of current model
    glBindVertexArray(_vao);

    // Render silhouette if object is selected
    if (_selected && _selected->value()) {
        // Disable depth test to render to background
        glDisable(GL_DEPTH_TEST);
        // Render using Silhouette Shader
        ShaderContainer::silhouetteShader()->use();
        glDrawElements(_renderingMode, _indices.size(), GL_UNSIGNED_INT, 0);
    }

    // Render object itself
    // Enable depth test to render object normally
    glEnable(GL_DEPTH_TEST);
    // Render using Low Poly Shader
    ShaderContainer::lowPolyShader()->use();
    glDrawElements(_renderingMode, _indices.size(), GL_UNSIGNED_INT, 0);
}

void Model::_setupBuffers() {
    // Enable model VAO to store Buffer Objects
    glBindVertexArray(_vao);
    // clang-format off
    /********** VBO **********/
    // Enable VBO
    glBindBuffer(GL_ARRAY_BUFFER, _vbo);
    // Upload Vertex Data
    glBufferData(GL_ARRAY_BUFFER, _vertices.size() * sizeof(Vertex), &_vertices[0], GL_STATIC_DRAW);

    // Get attribute information from vertices
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)0);
    glEnableVertexAttribArray(0);
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)offsetof(Vertex, normal));
    glEnableVertexAttribArray(1);
    glVertexAttribPointer(2, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)offsetof(Vertex, color));
    glEnableVertexAttribArray(2);
    // Disable VBO
    glBindBuffer(GL_ARRAY_BUFFER, 0);
    /********** VBO **********/

    /********** EBO **********/
    // Enable EBO
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, _ebo);
    // Upload Index Data
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, _indices.size() * sizeof(unsigned int), &_indices[0], GL_STATIC_DRAW);
    /********** EBO **********/

    // clang-format on
    // Disable VAO
    glBindVertexArray(0);

    // Disable EBO (AFTER VAO has been unbinded, otherwise they are not linked anymore)
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
}
