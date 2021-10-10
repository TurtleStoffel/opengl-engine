#include "engine/shaders/shaderregistry.hpp"

namespace Engine {
    ShaderRegistry::ShaderRegistry() {
        // Create uniform buffer object to store Model/View/Projection matrix
        glGenBuffers(1, &m_matrixUBO);
        glBindBuffer(GL_UNIFORM_BUFFER, m_matrixUBO);
        glBufferData(GL_UNIFORM_BUFFER, sizeof(glm::mat4) * 3, nullptr, GL_STREAM_DRAW);
        glBindBuffer(GL_UNIFORM_BUFFER, 0);
    }

    void ShaderRegistry::setViewProjectionMatrix(void* view, void* projection) const {
        glBindBuffer(GL_UNIFORM_BUFFER, m_matrixUBO);

        if (view) {
            glBufferSubData(GL_UNIFORM_BUFFER, sizeof(glm::mat4), sizeof(glm::mat4), view);
        }
        if (projection) {
            glBufferSubData(GL_UNIFORM_BUFFER,
                            sizeof(glm::mat4) * 2,
                            sizeof(glm::mat4),
                            projection);
        }

        glBindBuffer(GL_UNIFORM_BUFFER, 0);
    }

    void ShaderRegistry::setModelMatrix(void* model) const {
        glBindBuffer(GL_UNIFORM_BUFFER, m_matrixUBO);

        if (model) {
            glBufferSubData(GL_UNIFORM_BUFFER, 0, sizeof(glm::mat4), model);
        }

        glBindBuffer(GL_UNIFORM_BUFFER, 0);
    }
}