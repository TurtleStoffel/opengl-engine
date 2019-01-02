#include "shadercontainer.hpp"

Shader* ShaderContainer::lowPolyShader    = nullptr;
Shader* ShaderContainer::silhouetteShader = nullptr;

void ShaderContainer::init() {
    lowPolyShader = new Shader("../shaders/low-poly/vertex.glsl",
                               "../shaders/low-poly/geometry.glsl",
                               "../shaders/low-poly/fragment.glsl");

    silhouetteShader = new Shader("../shaders/silhouette/vertex.glsl",
                                  "../shaders/silhouette/fragment.glsl");
}

void ShaderContainer::destroy() {
    delete lowPolyShader;
    delete silhouetteShader;
}
