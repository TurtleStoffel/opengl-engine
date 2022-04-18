#pragma once

#include "engine/shaders/shader.hpp"

namespace Engine {
    class SilhouetteShader final : public Shader {
      public:
        SilhouetteShader();
        ~SilhouetteShader() override = default;
    };
}