#pragma once

#include "engine/shaders/shader.hpp"

namespace Engine::Shaders {
    class Star final : public Shader {
      public:
        Star()
              : Shader{"shaders/star/vertex.glsl", "shaders/star/fragment.glsl"} {};
        ~Star() override = default;
    };
}