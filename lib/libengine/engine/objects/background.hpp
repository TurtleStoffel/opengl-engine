#pragma once

#include "engine/shaders/shaderregistry.hpp"

#include <memory>

namespace Engine {
    class Entity;
}

namespace Engine {
    class Background {
      public:
        static auto createDefault(const ShaderRegistry& shaderRegistry) -> std::unique_ptr<Entity>;
    };
}