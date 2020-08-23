#pragma once

#include <memory>

#include "shader.hpp"

/**
 * Singleton class responsible for maintaining all shaders and data shared between the shaders
 */
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

    const Shader* getLowPolyShader() const;
    const Shader* getSilhouetteShader() const;
    const Shader* getGlowShader() const;

  private:
    GLuint _matrixUBO;

    std::unique_ptr<Shader> lowPolyShader;
    std::unique_ptr<Shader> silhouetteShader;
    std::unique_ptr<Shader> glowShader;
};