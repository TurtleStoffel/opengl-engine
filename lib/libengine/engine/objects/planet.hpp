#pragma once

#include <memory>

class ShaderRegistry;

namespace Engine {
    class Entity;
}

namespace Engine {
    class Planet final {
      public:
        static auto createDefault(float distance, float radius,
                                  const ShaderRegistry& shaderRegistry) -> std::unique_ptr<Entity>;
    };
}