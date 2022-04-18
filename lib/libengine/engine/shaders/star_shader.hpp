#pragma once

#include "engine/shaders/shader.hpp"

namespace Engine {
    class StarShader final : public Shader {
      public:
        StarShader()
              : Shader{"shaders/star/vertex.glsl", "shaders/star/fragment.glsl"} {};
        ~StarShader() override = default;
    };
}