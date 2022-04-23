#pragma once

#include "engine/shaders/registry.hpp"
#include "engine/systems/rendering.hpp"

#include <memory>

namespace Engine {
    class Entity;
}

namespace Engine {
    class Background {
      public:
        static auto createDefault(Shaders::Registry& shaderRegistry) -> std::unique_ptr<Entity>;
    };
}