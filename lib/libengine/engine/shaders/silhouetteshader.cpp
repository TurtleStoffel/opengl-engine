#include "engine/shaders/silhouetteshader.hpp"

SilhouetteShader::SilhouetteShader()
    : Shader{"shaders/silhouette/vertex.glsl", "shaders/silhouette/fragment.glsl"} {
}