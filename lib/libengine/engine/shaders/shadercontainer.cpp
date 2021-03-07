#include "engine/shaders/shadercontainer.hpp"

#include "engine/shaders/circleshader.hpp"
#include "engine/shaders/glowshader.hpp"
#include "engine/shaders/lowpolyshader.hpp"
#include "engine/shaders/silhouetteshader.hpp"

ShaderContainer::ShaderContainer() {
    // Create uniform buffer object to store Model/View/Projection matrix
    glGenBuffers(1, &_matrixUBO);
    glBindBuffer(GL_UNIFORM_BUFFER, _matrixUBO);
    glBufferData(GL_UNIFORM_BUFFER, sizeof(glm::mat4) * 3, nullptr, GL_STREAM_DRAW);
    glBindBuffer(GL_UNIFORM_BUFFER, 0);

    registerShader(std::make_unique<LowPolyShader>());
    registerShader(std::make_unique<CircleShader>());
    registerShader(std::make_unique<SilhouetteShader>());
    registerShader(std::make_unique<GlowShader>());
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