#pragma once

#include "shader.hpp"

class ShaderContainer {
  public:
    ShaderContainer();

    /**
     * View and Projection matrix are always set simultaneously by the Camera
     */
    void setViewProjectionMatrix(void* view, void* projection) const;
    /**
     * Model matrix is set separately by the Transform of the Object
     */
    void setModelMatrix(void* model) const;

    void useLowPolyShader() const;
    void useSilhouetteShader() const;
    void useGlowShader() const;

    void setCameraPosition(GLfloat* position) const;

  private:
    GLuint _matrixUBO;

    Shader lowPolyShader{"shaders/low-poly/vertex.glsl", "shaders/low-poly/fragment.glsl"};
    Shader silhouetteShader{"shaders/silhouette/vertex.glsl", "shaders/silhouette/fragment.glsl"};
    Shader glowShader{"shaders/glow/vertex.glsl", "shaders/glow/fragment.glsl"};
};