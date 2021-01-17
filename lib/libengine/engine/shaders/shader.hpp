#pragma once

#include <string>

#include "engine/opengl.hpp"

/**
 * Class responsible to hold all information for a specific Shader and responsible for all OpenGL
 * calls related to that specific shader.
 */
class Shader {
  public:
    Shader(const char* vertexShader, const char* geometryShader, const char* fragmentShader);
    Shader(const char* vertexShader, const char* fragmentShader);
    virtual ~Shader() = default;

    /**
     * Wrappers for OpenGL calls
     */
    // getters
    GLuint getUniformBlockIndex(const char* name);
    // other
    void uniformBlockBinding(GLuint blockIndex, GLuint bindingIndex);

    /**
     * Set current shader as active program in OpenGL
     */
    void use() const;

  protected:
    GLuint m_id;

  private:
    GLuint compileShader(const char* path, GLenum type);
    const char* getShaderType(GLenum type);
    void checkCompileErrors(GLuint shader, std::string type);
};