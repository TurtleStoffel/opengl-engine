#pragma once

#include "engine/shaderregistry.hpp"

#include <memory>

namespace Engine {
    class Entity;
}

namespace Engine {
    class Background {
      public:
        static auto createDefault(ShaderRegistry& shaderRegistry) -> std::unique_ptr<Entity>;
    };
}