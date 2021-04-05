#pragma once

#include <string>

#include "engine/opengl.hpp"

/**
 * Class responsible to hold all information for a specific Shader and responsible for all OpenGL
 * calls related to that specific shader.
 */
class Shader {
  public:
    static constexpr GLuint BINDING_INDEX{1};

    explicit Shader(const char* vertexShader, const char* fragmentShader);
    virtual ~Shader() = default;

    auto recompile() -> void;

    GLuint getUniformBlockIndex(const char* name);
    auto setMatrixBlockIndex(GLuint matrixBlockIndex) -> void;

    // Set current shader as active program in OpenGL
    void use() const;

  protected:
    GLuint m_id;
    GLuint m_matrixBlockIndex;

  private:
    auto compileShader() -> void;

    auto compilePartialShader(const char* path, GLenum type) -> GLuint;
    const char* getShaderType(GLenum type);
    void checkCompileErrors(GLuint shader, std::string type);

    std::string m_vertexShaderFilename;
    std::string m_fragmentShaderFilename;
};