#pragma once

#include "engine/entities/entity.hpp"
#include "engine/system/rendering.hpp"

#include <memory>

class ShaderRegistry;

namespace Engine {
    class Star final {
      public:
        static auto createDefault(ShaderRegistry& shaderRegistry) -> std::unique_ptr<Entity>;

      private:
        /**
         * @param[temperature] Kelvin
         */
        static auto calculateStarColor(int temperature) -> glm::vec3;
        static auto calculateTemperatureIndicator(int temperature) -> float;
    };
}