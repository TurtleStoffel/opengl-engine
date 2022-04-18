#include "engine/shaders/silhouette.hpp"

namespace Engine::Shaders {
    Silhouette::Silhouette()
          : Shader{"shaders/silhouette/vertex.glsl", "shaders/silhouette/fragment.glsl"} {
    }
}