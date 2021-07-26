#pragma once

#include "engine/objects/entity.hpp"

#include <memory>

class ShaderRegistry;

namespace Engine {
    class Sun final {
      public:
        static auto createDefault(const ShaderRegistry& shaderRegistry) -> std::unique_ptr<Entity>;
    };
}