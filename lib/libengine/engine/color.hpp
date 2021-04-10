#pragma once

#include <glm/glm.hpp>

namespace color {
    static constexpr auto brown  = glm::vec3{0.55f, 0.32f, 0.16f};
    static constexpr auto blue   = glm::vec3{0.0f, 0.0f, 0.75f};
    static constexpr auto green  = glm::vec3{0.1f, 0.75f, 0.1f};
    static constexpr auto yellow = glm::vec3{0.95f, 0.95f, 0.1f};
    static constexpr auto black  = glm::vec3{0.0f, 0.0f, 0.0f};

    /**
     * @param[temperature] Kelvin
     */
    glm::vec3 starColor(unsigned int temperature);

    float calculateTemperatureIndicator(unsigned int temperature);

} // namespace color