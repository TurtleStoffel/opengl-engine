#include "color.hpp"

#include <algorithm>
#include <cassert>
#include <math.h>

#include "util.hpp"

namespace Engine {
    auto Color::interpolate(const glm::vec3& source, const glm::vec3& target, float fraction)
        -> glm::vec3 {
        return (target - source) * fraction + source;
    }

    auto Color::starColor(int temperature) -> glm::vec3 {
        // Based on
        // https://stackoverflow.com/questions/21977786/star-b-v-color-index-to-apparent-rgb-color
        assert(temperature > 0);

        auto rawTemperatureIndicator = calculateTemperatureIndicator(temperature);
        auto temperatureIndicator    = std::clamp(rawTemperatureIndicator, -0.4f, 2.0f);

        glm::vec3 result;
        double t;

        if (temperatureIndicator < 0.0f) {
            t        = temperatureIndicator / 0.4f + 1.0f;
            result.r = 0.61 + (0.11 * t) + (0.1 * t * t);
        } else if (temperatureIndicator < 0.4f) {
            t        = temperatureIndicator / 0.4f;
            result.r = 0.83 + (0.17 * t);
        } else {
            result.r = 1.00;
        }

        if (temperatureIndicator < 0.0f) {
            t        = temperatureIndicator / 0.4f + 1.0f;
            result.g = 0.70 + (0.07 * t) + (0.1 * t * t);
        } else if (temperatureIndicator < 0.4f) {
            t        = temperatureIndicator / 0.4f;
            result.g = 0.87 + (0.11 * t);
        } else if (temperatureIndicator < 1.6f) {
            t        = (temperatureIndicator - 0.4f) / 1.2f;
            result.g = 0.98 - (0.16 * t);
        } else {
            t        = (temperatureIndicator - 1.60) / 0.4f;
            result.g = 0.82 - (0.5 * t * t);
        }

        if (temperatureIndicator < 0.4f) {
            t        = (temperatureIndicator + 0.40) / 0.8f;
            result.b = 1.00;
        } else if (temperatureIndicator < 1.5f) {
            t        = (temperatureIndicator - 0.40) / 1.1f;
            result.b = 1.00 - (0.47 * t) + (0.1 * t * t);
        } else if (temperatureIndicator < 1.94f) {
            t        = (temperatureIndicator - 1.50) / 0.44f;
            result.b = 0.63 - (0.6 * t * t);
        }

        return result;
    }

    auto Color::calculateTemperatureIndicator(int temperature) -> float {
        assert(temperature > 0);

        auto floatTemperature = static_cast<float>(temperature);

        return (-2.1344 * floatTemperature + 8464 +
                sqrt(0.98724096 * floatTemperature * floatTemperature + 71639296)) /
               (1.6928 * floatTemperature);
    }
}
