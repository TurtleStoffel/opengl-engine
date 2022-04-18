#include "engine/shaders/glowshader.hpp"

namespace Engine {
    GlowShader::GlowShader()
          : Shader{"shaders/glow/vertex.glsl", "shaders/glow/fragment.glsl"} {
    }
}