#include "engine/shaders/silhouetteshader.hpp"

namespace Engine {
    SilhouetteShader::SilhouetteShader()
          : Shader{"shaders/silhouette/vertex.glsl", "shaders/silhouette/fragment.glsl"} {
    }
}