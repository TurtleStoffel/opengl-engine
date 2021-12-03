#pragma once

#include "engine/shaderregistry.hpp"
#include "engine/system/rendering.hpp"

#include <memory>

namespace Engine {
    class Entity;
}

namespace Engine {
    class Planet final {
      public:
        static auto createDefault(float distance, float radius, ShaderRegistry& shaderRegistry,
                                  System::Rendering& renderingSystem) -> std::unique_ptr<Entity>;
    };
}