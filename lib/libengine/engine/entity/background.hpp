#pragma once

#include "engine/shaderregistry.hpp"
#include "engine/system/rendering.hpp"

#include <memory>

namespace Engine {
    class Entity;
}

namespace Engine {
    class Background {
      public:
        static auto createDefault(ShaderRegistry& shaderRegistry,
                                  System::Rendering& renderingSystem) -> std::unique_ptr<Entity>;
    };
}