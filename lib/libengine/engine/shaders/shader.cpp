#include "shader.hpp"

#include <fstream>
#include <sstream>

namespace Engine {
    Shader::Shader(std::string vertexShader, std::string fragmentShader)
          : m_vertexShaderFilename{vertexShader}
          , m_fragmentShaderFilename{fragmentShader} {
        compileShader();
    }

    auto Shader::recompile() -> void {
        glDeleteProgram(m_id);

        compileShader();

        setMatrixBlockIndex(m_matrixBlockIndex);
    }

    auto Shader::getUniformBlockIndex(const char* name) -> GLuint {
        return glGetUniformBlockIndex(m_id, name);
    }

    auto Shader::setMatrixBlockIndex(GLuint matrixBlockIndex) -> void {
        m_matrixBlockIndex = matrixBlockIndex;
        glUniformBlockBinding(m_id, m_matrixBlockIndex, BINDING_INDEX);
    }

    auto Shader::use() const -> void {
        glUseProgram(m_id);
    }

    auto Shader::compileShader() -> void {
        GLuint vShader = compilePartialShader(m_vertexShaderFilename, GL_VERTEX_SHADER);
        GLuint fShader = compilePartialShader(m_fragmentShaderFilename, GL_FRAGMENT_SHADER);

        m_id = glCreateProgram();
        glAttachShader(m_id, vShader);
        glAttachShader(m_id, fShader);
        glLinkProgram(m_id);
        checkCompileErrors(m_id, "Program");

        glDeleteShader(vShader);
        glDeleteShader(fShader);
    }

    auto Shader::compilePartialShader(const std::string& path, GLenum type) -> GLuint {
        SDL_Log("Compiling %s", path.c_str());
        std::string code;
        std::ifstream shaderFile;

        shaderFile.exceptions(std::ifstream::failbit | std::ifstream::badbit);
        try {
            shaderFile.open(path.c_str());
            std::stringstream shaderStream;
            shaderStream << shaderFile.rdbuf();

            shaderFile.close();
            code = shaderStream.str();
        } catch (std::ifstream::failure e) {
            SDL_Log("Unable to load shader file");
        }

        const char* shaderCode = code.c_str();
        GLuint shaderId        = glCreateShader(type);
        glShaderSource(shaderId, 1, &shaderCode, NULL);
        glCompileShader(shaderId);
        checkCompileErrors(shaderId, getShaderType(type));
        return shaderId;
    }

    auto Shader::getShaderType(GLenum type) -> const char* {
        switch (type) {
            case GL_VERTEX_SHADER:
                return "Vertex";
            case GL_GEOMETRY_SHADER:
                return "Geometry";
            case GL_FRAGMENT_SHADER:
                return "Fragment";
            default:
                return "Invalid shader type";
        }
    }

    auto Shader::checkCompileErrors(GLuint shader, std::string type) -> void {
        int success;
        char infoLog[1024];

        if (type != "Program") {
            glGetShaderiv(shader, GL_COMPILE_STATUS, &success);
            if (!success) {
                glGetShaderInfoLog(shader, 1024, NULL, infoLog);
                SDL_Log("Error shader compilation");
                SDL_Log("%s", infoLog);
            }
        } else {
            glGetProgramiv(shader, GL_LINK_STATUS, &success);
            if (!success) {
                glGetProgramInfoLog(shader, 1024, NULL, infoLog);
                SDL_Log("Error shader linking");
            }
        }
    }
}