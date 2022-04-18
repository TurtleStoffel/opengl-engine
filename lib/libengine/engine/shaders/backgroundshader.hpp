#pragma once

#include "engine/shaders/shader.hpp"

namespace Engine {
    class BackgroundShader final : public Shader {
      public:
        BackgroundShader()
              : Shader{"shaders/background/vertex.glsl", "shaders/background/fragment.glsl"} {
        }
    };
}