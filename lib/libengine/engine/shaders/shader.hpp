#pragma once

#include <string>

#include "engine/opengl.hpp"

namespace Engine::Shaders {
    /**
     * Class responsible to hold all information for a specific Shader and responsible for all
     * OpenGL calls related to that specific shader.
     */
    class Shader {
      public:
        static constexpr GLuint BINDING_INDEX{1};

        explicit Shader(std::string vertexShader, std::string fragmentShader);
        virtual ~Shader() = default;

        auto recompile() -> void;

        auto getUniformBlockIndex(const char* name) -> GLuint;
        auto setMatrixBlockIndex(GLuint matrixBlockIndex) -> void;

        // Set current shader as active program in OpenGL
        auto use() const -> void;

      protected:
        GLuint m_id;

      private:
        auto compileShader() -> void;

        auto compilePartialShader(const std::string& path, GLenum type) -> GLuint;
        auto getShaderType(GLenum type) -> const char*;
        auto checkCompileErrors(GLuint shader, std::string type) -> void;

        std::string m_vertexShaderFilename;
        std::string m_fragmentShaderFilename;
        GLuint m_matrixBlockIndex;
    };
}