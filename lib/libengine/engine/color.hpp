#pragma once

#include <glm/glm.hpp>

namespace color {

glm::vec3 brown();
glm::vec3 blue();
glm::vec3 green();
glm::vec3 yellow();

const glm::vec3 black = glm::vec3(0.0f, 0.0f, 0.0f);

/**
 * @param[temperature] Kelvin
 */
glm::vec3 starColor(unsigned int temperature);

float calculateTemperatureIndicator(unsigned int temperature);

} // namespace color