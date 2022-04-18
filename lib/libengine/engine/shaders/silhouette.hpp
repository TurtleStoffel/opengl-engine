#pragma once

#include "engine/shaders/shader.hpp"

namespace Engine::Shaders {
    class Silhouette final : public Shader {
      public:
        Silhouette();
        ~Silhouette() override = default;
    };
}