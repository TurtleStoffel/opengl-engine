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
}