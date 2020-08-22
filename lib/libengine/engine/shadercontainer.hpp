#pragma once

#include "shader.hpp"

/**
 * Singleton class responsible for maintaining all shaders and data shared between the shaders
 */
class ShaderContainer {
  public:
    static ShaderContainer* instance();
    static void init();

    /**
     * View and Projection matrix are always set simultaneously by the Camera
     */
    void setViewProjectionMatrix(void* view, void* projection);
    /**
     * Model matrix is set separately by the Transform of the Object
     */
    void setModelMatrix(void* model);
    static Shader* lowPolyShader();
    static Shader* silhouetteShader();
    static Shader* glowShader();

  private:
    ShaderContainer();
    ~ShaderContainer();

    static ShaderContainer* _instance;

    GLuint _matrixUBO;

    Shader* _lowPolyShader;
    Shader* _silhouetteShader;
    Shader* _glowShader;
};