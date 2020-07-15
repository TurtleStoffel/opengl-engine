#include "model.hpp"

#include "opengl.hpp"
#include "shadercontainer.hpp"

Model::Model(Transform* pTransform) {
    _pTransform = pTransform;

    _generateOpenGLBuffers();
}

Model::Model() : Model(nullptr) {
}

void Model::_generateOpenGLBuffers() {
    glGenVertexArrays(1, &_vertexArrayObject);
    glGenBuffers(1, &_vertexBufferObject);
    glGenBuffers(1, &_elementBufferObject);
}

void Model::render(bool selected) const {
    _pTransform->passModelMatrixToShader();

    // Enable rendering data of current Model
    glBindVertexArray(_vertexArrayObject);

    if (selected) {
        _renderSilhouette();
    }
    _renderModel();
}

void Model::_renderSilhouette() const {
    // Disable depth test to render to background
    glDisable(GL_DEPTH_TEST);
    // Render using Silhouette Shader
    ShaderContainer::silhouetteShader()->use();
    glDrawElements(_renderingMode, _indices.size(), GL_UNSIGNED_INT, 0);

    glEnable(GL_DEPTH_TEST);
}

void Model::_renderModel() const {
    ShaderContainer::lowPolyShader()->use();
    glDrawElements(_renderingMode, _indices.size(), GL_UNSIGNED_INT, 0);
}

void Model::_setupBuffers() {
    // Enable model VAO to store Buffer Objects
    glBindVertexArray(_vertexArrayObject);
    // clang-format off
    /********** VBO **********/
    // Enable VBO
    glBindBuffer(GL_ARRAY_BUFFER, _vertexBufferObject);
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
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, _elementBufferObject);
    // Upload Index Data
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, _indices.size() * sizeof(unsigned int), &_indices[0], GL_STATIC_DRAW);
    /********** EBO **********/

    // clang-format on
    // Disable VAO
    glBindVertexArray(0);

    // Disable EBO (AFTER VAO has been unbinded, otherwise they are not linked anymore)
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
}
