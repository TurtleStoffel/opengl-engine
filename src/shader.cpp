#include "shader.hpp"

#include <fstream>
#include <iostream>
#include <sstream>
#include <string>

Shader::Shader(const char* vertexShader, const char* geometryShader, const char* fragmentShader) {
    GLuint vShader = _compileShader(vertexShader, GL_VERTEX_SHADER);
    GLuint gShader = _compileShader(geometryShader, GL_GEOMETRY_SHADER);
    GLuint fShader = _compileShader(fragmentShader, GL_FRAGMENT_SHADER);

    _ID = glCreateProgram();
    glAttachShader(_ID, vShader);
    glAttachShader(_ID, gShader);
    glAttachShader(_ID, fShader);
    glLinkProgram(_ID);
    _checkCompileErrors(_ID, "Program");

    glDeleteShader(vShader);
    glDeleteShader(gShader);
    glDeleteShader(fShader);
}

Shader::Shader(const char* vertexShader, const char* fragmentShader) {
    GLuint vShader = _compileShader(vertexShader, GL_VERTEX_SHADER);
    GLuint fShader = _compileShader(fragmentShader, GL_FRAGMENT_SHADER);

    _ID = glCreateProgram();
    glAttachShader(_ID, vShader);
    glAttachShader(_ID, fShader);
    glLinkProgram(_ID);
    _checkCompileErrors(_ID, "Program");

    glDeleteShader(vShader);
    glDeleteShader(fShader);
}

GLuint Shader::getUniformBlockIndex(const char* name) {
    return glGetUniformBlockIndex(_ID, name);
}

void Shader::setUniform3fv(const char* name, GLfloat* value) {
    GLuint location = glGetUniformLocation(_ID, name);
    glUniform3fv(location, 1, value);
}

void Shader::uniformBlockBinding(GLuint blockIndex, GLuint bindingIndex) {
    glUniformBlockBinding(_ID, blockIndex, bindingIndex);
}

void Shader::use() {
    glUseProgram(_ID);
}

GLuint Shader::_compileShader(const char* path, GLenum type) {
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
        std::cout << "Unable to load shader file" << std::endl;
    }

    const char* shaderCode = code.c_str();
    GLuint shaderId        = glCreateShader(type);
    glShaderSource(shaderId, 1, &shaderCode, NULL);
    glCompileShader(shaderId);
    _checkCompileErrors(shaderId, _getShaderType(type));
    return shaderId;
}

const char* Shader::_getShaderType(GLenum type) {
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

void Shader::_checkCompileErrors(GLuint shader, std::string type) {
    int success;
    char infoLog[1024];

    if (type != "Program") {
        glGetShaderiv(shader, GL_COMPILE_STATUS, &success);
        if (!success) {
            glGetShaderInfoLog(shader, 1024, NULL, infoLog);
            std::cout << "Error shader compilation of type: " << type << std::endl
                      << infoLog << std::endl;
        }
    } else {
        glGetProgramiv(shader, GL_LINK_STATUS, &success);
        if (!success) {
            glGetProgramInfoLog(shader, 1024, NULL, infoLog);
            std::cout << "Error shader linking of type: " << type << std::endl
                      << infoLog << std::endl;
        }
    }
}
