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
}