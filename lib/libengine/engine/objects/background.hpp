#pragma once

#include "engine/objects/entity.hpp"

#include <memory>

class ShaderRegistry;

namespace Engine {
    class Background : public Entity {
      public:
        static auto createDefault(const ShaderRegistry& shaderRegistry)
            -> std::unique_ptr<Background>;

        Background();
        ~Background() override = default;
    };
}