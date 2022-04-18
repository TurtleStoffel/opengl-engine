#pragma once

#include "engine/shaders/shader.hpp"

namespace Engine::Shaders {
    class Background final : public Shader {
      public:
        Background()
              : Shader{"shaders/background/vertex.glsl", "shaders/background/fragment.glsl"} {
        }
    };
}