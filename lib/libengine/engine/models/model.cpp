#include "model.hpp"

#include "models/effects/effect.hpp"
#include "opengl.hpp"
#include "shadercontainer.hpp"

Model::Model(Transform* pTransform) {
    _pTransform = pTransform;

    _generateOpenGLBuffers();
}

Model::Model() : Model(nullptr) {
}

Model::~Model() {
}

void Model::_generateOpenGLBuffers() {
    glGenVertexArrays(1, &_vertexArrayObject);
    glGenBuffers(1, &_vertexBufferObject);
    glGenBuffers(1, &_elementBufferObject);
}

void Model::render(bool selected, const ShaderContainer& shaderContainer) const {
    _pTransform->passModelMatrixToShader(shaderContainer);
    glBindVertexArray(_vertexArrayObject);

    for (const std::unique_ptr<Effect>& effect : preRenderEffects) {
        effect->render(selected, shaderContainer);
    }

    shaderContainer.useLowPolyShader();
    glDrawElements(_renderingMode, indices.size(), GL_UNSIGNED_INT, 0);

    glBindVertexArray(0);
}

void Model::glDraw() const {
    glDrawElements(_renderingMode, indices.size(), GL_UNSIGNED_INT, 0);
}

void Model::addEffect(std::unique_ptr<Effect> effect) {
    preRenderEffects.push_back(std::move(effect));
}

void Model::_setupBuffers() {
    // Enable model VAO to store Buffer Objects
    glBindVertexArray(_vertexArrayObject);
    // clang-format off
    /********** VBO **********/
    // Enable VBO
    glBindBuffer(GL_ARRAY_BUFFER, _vertexBufferObject);
    // Upload Vertex Data
    glBufferData(GL_ARRAY_BUFFER, vertices.size() * sizeof(Vertex), &vertices[0], GL_STATIC_DRAW);

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
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, indices.size() * sizeof(unsigned int), &indices[0], GL_STATIC_DRAW);
    /********** EBO **********/

    // clang-format on
    // Disable VAO
    glBindVertexArray(0);

    // Disable EBO (AFTER VAO has been unbinded, otherwise they are not linked anymore)
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
}
