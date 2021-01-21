#include "model.hpp"

#include "engine/models/effects/effect.hpp"
#include "engine/models/vector.hpp"
#include "engine/objects/object.hpp"
#include "engine/objects/transform.hpp"
#include "engine/opengl.hpp"
#include "engine/shaders/shadercontainer.hpp"

Model::Model(const Object& object) : m_object{object} {
    _generateOpenGLBuffers();
}

void Model::_generateOpenGLBuffers() {
    glGenVertexArrays(1, &_vertexArrayObject);
    glGenBuffers(1, &_vertexBufferObject);
    glGenBuffers(1, &_elementBufferObject);
}

void Model::render(const ShaderContainer& shaderContainer) const {
    glBindVertexArray(_vertexArrayObject);

    for (const auto& effect : preRenderEffects) {
        effect->render(shaderContainer);
    }

    shaderContainer.lowPolyShader().use();

    if (m_preRenderLogic) {
        m_preRenderLogic(shaderContainer);
    }

    glDrawElements(m_renderingMode, m_indices.size(), GL_UNSIGNED_INT, 0);

    for (const auto& effect : m_postRenderEffects) {
        effect->render(shaderContainer);
    }

    glBindVertexArray(0);
}

void Model::glDraw() const {
    glDrawElements(m_renderingMode, m_indices.size(), GL_UNSIGNED_INT, 0);
}

auto Model::setPreRenderLogic(std::function<void(const ShaderContainer&)> preRenderLogic) -> void {
    m_preRenderLogic = preRenderLogic;
}

void Model::addPreRenderEffect(std::unique_ptr<Effect> effect) {
    preRenderEffects.push_back(std::move(effect));
}

void Model::addPostRenderEffect(std::unique_ptr<Effect> effect) {
    m_postRenderEffects.push_back(std::move(effect));
}

void Model::setupBuffers() {
    // Enable model VAO to store Buffer Objects
    glBindVertexArray(_vertexArrayObject);
    // clang-format off
    /********** VBO **********/
    // Enable VBO
    glBindBuffer(GL_ARRAY_BUFFER, _vertexBufferObject);
    // Upload Vertex Data
    glBufferData(GL_ARRAY_BUFFER, m_vertices.size() * sizeof(Vertex), &m_vertices[0], GL_STATIC_DRAW);

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
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, m_indices.size() * sizeof(unsigned int), &m_indices[0], GL_STATIC_DRAW);
    /********** EBO **********/

    // clang-format on
    // Disable VAO
    glBindVertexArray(0);

    // Disable EBO (AFTER VAO has been unbinded, otherwise they are not linked anymore)
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
}

auto Model::getSelected() const -> bool {
    return m_object.getSelected();
}