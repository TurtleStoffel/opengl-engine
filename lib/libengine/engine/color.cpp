#include "color.hpp"

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
}  // namespace color
