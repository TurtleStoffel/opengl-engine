#include "shader.hpp"

#include <fstream>
#include <sstream>
#include <string>

Shader::Shader(const char* vertexShader, const char* fragmentShader) {
    GLuint vShader = compileShader(vertexShader, GL_VERTEX_SHADER);
    GLuint fShader = compileShader(fragmentShader, GL_FRAGMENT_SHADER);

    m_id = glCreateProgram();
    glAttachShader(m_id, vShader);
    glAttachShader(m_id, fShader);
    glLinkProgram(m_id);
    checkCompileErrors(m_id, "Program");

    glDeleteShader(vShader);
    glDeleteShader(fShader);
}

GLuint Shader::getUniformBlockIndex(const char* name) {
    return glGetUniformBlockIndex(m_id, name);
}

void Shader::uniformBlockBinding(GLuint blockIndex, GLuint bindingIndex) {
    glUniformBlockBinding(m_id, blockIndex, bindingIndex);
}

void Shader::use() const {
    glUseProgram(m_id);
}

GLuint Shader::compileShader(const char* path, GLenum type) {
    SDL_Log("Compiling %s", path);
    std::string code;
    std::ifstream shaderFile;

    shaderFile.exceptions(std::ifstream::failbit | std::ifstream::badbit);
    try {
        shaderFile.open(path);
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

const char* Shader::getShaderType(GLenum type) {
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

void Shader::checkCompileErrors(GLuint shader, std::string type) {
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
