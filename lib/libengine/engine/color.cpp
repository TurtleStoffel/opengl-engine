#include "color.hpp"

#include <math.h>

#include "util.hpp"

namespace color {

glm::vec3 brown() {
    // clang-format off
    return glm::vec3(util::randf(0.50f, 0.60f),
                     util::randf(0.27f, 0.37f),
                     util::randf(0.11f, 0.21f));
    // clang-format on
}

glm::vec3 blue() {
    // clang-format off
    return glm::vec3(util::randf(0.0f, 0.0f),
                     util::randf(0.0f, 0.0f),
                     util::randf(0.5f, 1.0f));
    // clang-format on
}

glm::vec3 green() {
    // clang-format off
    return glm::vec3(util::randf(0.0f, 0.2f),
                     util::randf(0.5f, 1.0f),
                     util::randf(0.0f, 0.2f));
    // clang-format on
}

glm::vec3 yellow() {
    // clang-format off
    return glm::vec3(util::randf(0.9f, 1.0f),
                     util::randf(0.9f, 1.0f),
                     util::randf(0.0f, 0.2f));
    // clang-format on
}

glm::vec3 starColor(unsigned int temperature) {
    // Based on
    // https://stackoverflow.com/questions/21977786/star-b-v-color-index-to-apparent-rgb-color

    // [-0.4; 2.0]
    float bv = calculateTemperatureIndicator(temperature);
    double t;
    double r = 0.0;
    double g = 0.0;
    double b = 0.0;
    if (bv < -0.4) {
        bv = -0.4;
    }
    if (bv > 2.0) {
        bv = 2.0;
    }
    if ((bv >= -0.40) && (bv < 0.00)) {
        t = (bv + 0.40) / (0.00 + 0.40);
        r = 0.61 + (0.11 * t) + (0.1 * t * t);
    } else if ((bv >= 0.00) && (bv < 0.40)) {
        t = (bv - 0.00) / (0.40 - 0.00);
        r = 0.83 + (0.17 * t);
    } else if ((bv >= 0.40) && (bv < 2.10)) {
        t = (bv - 0.40) / (2.10 - 0.40);
        r = 1.00;
    }
    if ((bv >= -0.40) && (bv < 0.00)) {
        t = (bv + 0.40) / (0.00 + 0.40);
        g = 0.70 + (0.07 * t) + (0.1 * t * t);
    } else if ((bv >= 0.00) && (bv < 0.40)) {
        t = (bv - 0.00) / (0.40 - 0.00);
        g = 0.87 + (0.11 * t);
    } else if ((bv >= 0.40) && (bv < 1.60)) {
        t = (bv - 0.40) / (1.60 - 0.40);
        g = 0.98 - (0.16 * t);
    } else if ((bv >= 1.60) && (bv < 2.00)) {
        t = (bv - 1.60) / (2.00 - 1.60);
        g = 0.82 - (0.5 * t * t);
    }
    if ((bv >= -0.40) && (bv < 0.40)) {
        t = (bv + 0.40) / (0.40 + 0.40);
        b = 1.00;
    } else if ((bv >= 0.40) && (bv < 1.50)) {
        t = (bv - 0.40) / (1.50 - 0.40);
        b = 1.00 - (0.47 * t) + (0.1 * t * t);
    } else if ((bv >= 1.50) && (bv < 1.94)) {
        t = (bv - 1.50) / (1.94 - 1.50);
        b = 0.63 - (0.6 * t * t);
    }

    return glm::vec3(r, g, b);
}

float calculateTemperatureIndicator(unsigned int temperature) {
    float floatTemperature = (float)temperature;

    return (-2.1344 * floatTemperature + 8464 +
            sqrt(0.98724096 * floatTemperature * floatTemperature + 71639296)) /
           (1.6928 * floatTemperature);
}

} // namespace color
