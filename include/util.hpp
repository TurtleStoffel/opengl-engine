#ifndef UTIL_HPP
#define UTIL_HPP

#include "opengl.hpp"

namespace util {

float randf();
float randf(float min, float max);

// Return random angle in radians [0, 2 Pi]
float randRadian();

int randi(int min, int max);

}  // namespace util

#endif
