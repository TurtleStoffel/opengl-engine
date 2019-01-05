#ifndef SHADER_CONTAINER_HPP
#define SHADER_CONTAINER_HPP

#include "shader.hpp"

/**
 * Singleton class responsible for maintaining all shaders and data shared between the shaders
 */
class ShaderContainer {
   public:
    static ShaderContainer* instance();
    static void init();

    void setModelViewProjectionMatrix(void* model, void* view, void* projection);
    static Shader* lowPolyShader();
    static Shader* silhouetteShader();

   private:
    ShaderContainer();
    ~ShaderContainer();

    static ShaderContainer* _instance;

    GLuint _matrixUBO;

    Shader* _lowPolyShader;
    Shader* _silhouetteShader;
};

#endif
