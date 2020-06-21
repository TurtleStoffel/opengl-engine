#include "util.hpp"

#include <math.h>

namespace util {

float randf() {
    return float(rand()) / RAND_MAX;
}

float randf(float min, float max) {
    return randf() * (max - min) + min;
}

float randRadian() {
    return randf(0.0f, 2 * M_PI);
}

int randi(int min, int max) {
    return rand() % (max - min + 1) + min;
}

}  // namespace util
