#include "engine/random.hpp"

#include <math.h>

namespace Engine::Random {
    auto randf() -> float {
        return static_cast<float>(rand()) / static_cast<float>(RAND_MAX);
    }

    auto randf(float min, float max) -> float {
        return randf() * (max - min) + min;
    }

    auto randRadian() -> float {
        return randf(0.0f, 2 * M_PI);
    }

    auto randi(int min, int max) -> int {
        return rand() % (max - min + 1) + min;
    }

    auto randi(int max) -> int {
        return randi(0, max);
    }
}