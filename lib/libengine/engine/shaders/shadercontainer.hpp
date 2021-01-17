#pragma once

#include "engine/shaders/lowpolyshader.hpp"
#include "engine/shaders/shader.hpp"

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

    auto lowPolyShader() const -> const LowPolyShader&;
    void useSilhouetteShader() const;
    void useGlowShader() const;

  private:
    GLuint _matrixUBO;

    LowPolyShader m_lowPolyShader;
    Shader silhouetteShader{"shaders/silhouette/vertex.glsl", "shaders/silhouette/fragment.glsl"};
    Shader glowShader{"shaders/glow/vertex.glsl", "shaders/glow/fragment.glsl"};
};