#include "engine/shaders/glow.hpp"

namespace Engine::Shaders {
    Glow::Glow()
          : Shader{"shaders/glow/vertex.glsl", "shaders/glow/fragment.glsl"} {
    }
}