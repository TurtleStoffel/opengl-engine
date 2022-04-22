#pragma once

#include "engine/scene.hpp"
#include "engine/shaders/registry.hpp"

namespace ModelEditor {
    class Scene final : public Engine::Scene {
      public:
        Scene(Engine::Shaders::Registry& shaderRegistry);
        ~Scene() override = default;
    };
}