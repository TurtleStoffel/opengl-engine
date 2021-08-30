#pragma once

#include <glm/glm.hpp>

namespace Engine {
    class Color final {
      public:
        static constexpr auto brown       = glm::vec3{0.55f, 0.32f, 0.16f};
        static constexpr auto blue        = glm::vec3{0.00f, 0.00f, 0.75f};
        static constexpr auto green       = glm::vec3{0.10f, 0.75f, 0.10f};
        static constexpr auto darkGreen   = glm::vec3{0.25f, 0.40f, 0.00f};
        static constexpr auto greenYellow = glm::vec3{0.66f, 0.76f, 0.39f};
        static constexpr auto yellow      = glm::vec3{0.95f, 0.95f, 0.10f};
        static constexpr auto black       = glm::vec3{0.00f, 0.00f, 0.00f};
        static constexpr auto grey        = glm::vec3{0.75f, 0.75f, 0.75f};
        static constexpr auto darkGrey    = glm::vec3{0.50f, 0.50f, 0.50f};

        static auto interpolate(const glm::vec3& source, const glm::vec3& target, float fraction)
            -> glm::vec3;

        /**
         * @param[temperature] Kelvin
         */
        static auto starColor(int temperature) -> glm::vec3;

      private:
        static auto calculateTemperatureIndicator(int temperature) -> float;
    };
}