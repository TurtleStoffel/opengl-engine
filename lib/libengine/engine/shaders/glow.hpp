#pragma once

#include "engine/shaders/shader.hpp"

namespace Engine::Shaders {
    class Glow final : public Shader {
      public:
        Glow();
        ~Glow() override = default;
    };
}