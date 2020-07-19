#include "gtest/gtest.h"

#include <iostream>

#include "color.hpp"

TEST(colors, starColor) {
    float maxError = 0.0001f;

    glm::vec3 color = color::starColor(3500);
    ASSERT_NEAR(color.r, 1.0f, maxError);
    ASSERT_NEAR(color.g, 0.780692f, maxError);
    ASSERT_NEAR(color.b, 0.490507f, maxError);

    color = color::starColor(7000);
    ASSERT_NEAR(color.r, 0.990619f, maxError);
    ASSERT_NEAR(color.g, 0.97393f, maxError);
    ASSERT_NEAR(color.b, 1.0f, maxError);

    color = color::starColor(12000);
    ASSERT_NEAR(color.r, 0.733268f, maxError);
    ASSERT_NEAR(color.g, 0.795707f, maxError);
    ASSERT_NEAR(color.b, 1.0f, maxError);

    color = color::starColor(17000);
    ASSERT_NEAR(color.r, 0.639724f, maxError);
    ASSERT_NEAR(color.g, 0.720747f, maxError);
    ASSERT_NEAR(color.b, 1.0f, maxError);
}