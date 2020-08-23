#pragma once

#include <string>

#include "opengl.hpp"

/**
 * Class responsible to hold all information for a specific Shader and responsible for all OpenGL
 * calls related to that specific shader.
 */
class Shader {
  public:
    Shader(const char* vertexShader, const char* geometryShader, const char* fragmentShader);
    Shader(const char* vertexShader, const char* fragmentShader);

    /**
     * Wrappers for OpenGL calls
     */
    // getters
    GLuint getUniformBlockIndex(const char* name);
    // setters
    void setUniform3fv(const char* name, GLfloat* value) const;
    // other
    void uniformBlockBinding(GLuint blockIndex, GLuint bindingIndex);

    /**
     * Set current shader as active program in OpenGL
     */
    void use() const;

  private:
    GLuint _compileShader(const char* path, GLenum type);
    const char* _getShaderType(GLenum type);
    void _checkCompileErrors(GLuint shader, std::string type);

    GLuint _ID;
};