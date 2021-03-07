#pragma once

#include "engine/opengl.hpp"
#include "engine/shaders/shader.hpp"

#include <memory>
#include <stdexcept>
#include <typeinfo>
#include <unordered_map>

#include <glm/glm.hpp>

// TODO rename to ShaderRegistry
class ShaderRegistry final {
  public:
    ShaderRegistry();

    /**
     * View and Projection matrix are always set simultaneously by the Camera
     */
    void setViewProjectionMatrix(void* view, void* projection) const;
    /**
     * Model matrix is set separately by the Transform of the Object
     */
    void setModelMatrix(void* model) const;

    template <typename TShaderType>
    auto get() const -> const TShaderType&;

  private:
    static constexpr GLuint BINDING_INDEX = 1;

    template <typename TShaderType>
    auto registerShader(std::unique_ptr<TShaderType> shader) -> void;

    GLuint m_matrixUBO;
    GLuint m_matrixBlockIndex{GL_INVALID_INDEX};

    std::unordered_map<std::size_t, std::unique_ptr<Shader>> m_shaders;
};

template <typename TShaderType>
auto ShaderRegistry::get() const -> const TShaderType& {
    auto iterator = m_shaders.find(typeid(TShaderType).hash_code());
    if (iterator == m_shaders.end()) {
        throw std::invalid_argument("No shader with type" +
                                    std::string{typeid(TShaderType).name()});
    }
    return static_cast<TShaderType&>(*iterator->second);
}

template <typename TShaderType>
auto ShaderRegistry::registerShader(std::unique_ptr<TShaderType> shader) -> void {
    if (m_matrixBlockIndex == GL_INVALID_INDEX) {
        // Bind Uniform Block to Uniform Buffer Object
        m_matrixBlockIndex = shader->getUniformBlockIndex("ModelViewProjection");
        // Bind buffer to index
        glBindBufferRange(GL_UNIFORM_BUFFER, BINDING_INDEX, m_matrixUBO, 0, sizeof(glm::mat4) * 3);
    }

    shader->uniformBlockBinding(m_matrixBlockIndex, BINDING_INDEX);

    SDL_LogInfo(SDL_LOG_CATEGORY_SYSTEM,
                "Registering Shader with ID %s",
                typeid(TShaderType).name());

    m_shaders.insert({typeid(TShaderType).hash_code(), std::move(shader)});
}