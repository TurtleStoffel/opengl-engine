#include "util.hpp"

namespace util {

float randf() { return float(rand()) / RAND_MAX; }

float randf(float min, float max) { return randf() * (max - min) + min; }
}
