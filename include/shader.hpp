#ifndef SHADER_HPP
#define SHADER_HPP

#include <string>

#include "opengl.hpp"

class Shader {
   public:
    Shader(const char* vertexShader, const char* geometryShader, const char* fragmentShader);
    Shader(const char* vertexShader, const char* fragmentShader);

    void use();
    GLuint _ID;

   private:
    GLuint _compileShader(const char* path, GLenum type);
    const char* _getShaderType(GLenum type);
    void _checkCompileErrors(GLuint shader, std::string type);
};

#endif
