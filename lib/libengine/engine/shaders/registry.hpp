#pragma once

#include "engine/opengl.hpp"
#include "engine/shaders/shader.hpp"

#include <assert.h>
#include <memory>
#include <stdexcept>
#include <typeinfo>
#include <unordered_map>

#include <glm/glm.hpp>

namespace Engine::Shaders {
    class Registry final {
      public:
        Registry();

        /**
         * View and Projection matrix are always set simultaneously by the Camera
         */
        void setViewProjectionMatrix(void* view, void* projection) const;
        /**
         * Model matrix is set separately by the Transform of the Entity
         */
        void setModelMatrix(void* model) const;

        template <typename TShaderType>
        auto getOrCreate() -> TShaderType&;

      private:
        template <typename TShaderType>
        auto registerShader(std::unique_ptr<TShaderType> shader);

        GLuint m_matrixUBO;
        GLuint m_matrixBlockIndex{GL_INVALID_INDEX};

        std::unordered_map<std::size_t, std::unique_ptr<Shader>> m_shaders;
    };

    template <typename TShaderType>
    auto Registry::getOrCreate() -> TShaderType& {
        auto iterator = m_shaders.find(typeid(TShaderType).hash_code());
        if (iterator == m_shaders.end()) {
            iterator = registerShader(std::make_unique<TShaderType>());
        }
        return static_cast<TShaderType&>(*iterator->second);
    }

    template <typename TShaderType>
    auto Registry::registerShader(std::unique_ptr<TShaderType> shader) {
        if (m_matrixBlockIndex == GL_INVALID_INDEX) {
            // Bind Uniform Block to Uniform Buffer Object
            m_matrixBlockIndex = shader->getUniformBlockIndex("ModelViewProjection");
            // Bind buffer to index
            glBindBufferRange(GL_UNIFORM_BUFFER,
                              Shader::BINDING_INDEX,
                              m_matrixUBO,
                              0,
                              sizeof(glm::mat4) * 3);
        }
        shader->setMatrixBlockIndex(m_matrixBlockIndex);

        SDL_LogInfo(SDL_LOG_CATEGORY_SYSTEM,
                    "Registering Shader with ID %s",
                    typeid(TShaderType).name());

        auto result = m_shaders.insert({typeid(TShaderType).hash_code(), std::move(shader)});
        assert(result.second);
        return result.first;
    }
}