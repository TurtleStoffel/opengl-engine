#include "shadercontainer.hpp"

#include <glm/glm.hpp>

ShaderContainer::ShaderContainer() {
    // Create uniform buffer object to store Model/View/Projection matrix
    glGenBuffers(1, &_matrixUBO);
    glBindBuffer(GL_UNIFORM_BUFFER, _matrixUBO);
    glBufferData(GL_UNIFORM_BUFFER, sizeof(glm::mat4) * 3, nullptr, GL_STREAM_DRAW);
    glBindBuffer(GL_UNIFORM_BUFFER, 0);

    // Bind Uniform Block to Uniform Buffer Object
    GLuint bindingIndex     = 1;
    GLuint matrixBlockIndex = m_lowPolyShader.getUniformBlockIndex("ModelViewProjection");
    // Bind shader block to index
    m_lowPolyShader.uniformBlockBinding(matrixBlockIndex, bindingIndex);
    m_circleShader.uniformBlockBinding(matrixBlockIndex, bindingIndex);
    silhouetteShader.uniformBlockBinding(matrixBlockIndex, bindingIndex);
    glowShader.uniformBlockBinding(matrixBlockIndex, bindingIndex);
    // Bind buffer to index
    glBindBufferRange(GL_UNIFORM_BUFFER, bindingIndex, _matrixUBO, 0, sizeof(glm::mat4) * 3);
}

auto ShaderContainer::lowPolyShader() const -> const LowPolyShader& {
    return m_lowPolyShader;
}

auto ShaderContainer::circleShader() const -> const CircleShader& {
    return m_circleShader;
}

void ShaderContainer::useSilhouetteShader() const {
    silhouetteShader.use();
}

void ShaderContainer::useGlowShader() const {
    glowShader.use();
}

void ShaderContainer::setViewProjectionMatrix(void* view, void* projection) const {
    glBindBuffer(GL_UNIFORM_BUFFER, _matrixUBO);

    if (view) {
        glBufferSubData(GL_UNIFORM_BUFFER, sizeof(glm::mat4), sizeof(glm::mat4), view);
    }
    if (projection) {
        glBufferSubData(GL_UNIFORM_BUFFER, sizeof(glm::mat4) * 2, sizeof(glm::mat4), projection);
    }

    glBindBuffer(GL_UNIFORM_BUFFER, 0);
}

void ShaderContainer::setModelMatrix(void* model) const {
    glBindBuffer(GL_UNIFORM_BUFFER, _matrixUBO);

    if (model) {
        glBufferSubData(GL_UNIFORM_BUFFER, 0, sizeof(glm::mat4), model);
    }

    glBindBuffer(GL_UNIFORM_BUFFER, 0);
}