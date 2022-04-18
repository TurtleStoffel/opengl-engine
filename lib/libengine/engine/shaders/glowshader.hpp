#pragma once

#include "engine/shaders/shader.hpp"

namespace Engine {
    class GlowShader final : public Shader {
      public:
        GlowShader();
        ~GlowShader() override = default;
    };
}