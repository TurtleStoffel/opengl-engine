#pragma once

#include "engine/shaders/registry.hpp"
#include "engine/systems/rendering.hpp"

#include <memory>

namespace Engine {
    class Entity;
}

namespace Engine {
    class Planet final {
      public:
        static auto createDefault(float distance, float radius, Shaders::Registry& shaderRegistry)
            -> std::unique_ptr<Entity>;
    };
}