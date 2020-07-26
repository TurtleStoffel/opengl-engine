#include "gtest/gtest.h"

#include <glm/gtc/constants.hpp>

#include "objects/transform.hpp"

TEST(transform, translation) {
    // Given
    std::unique_ptr<Transform> transform = std::make_unique<Transform>();

    // When
    transform->translate(glm::vec3(1.0f, 0.0f, 0.0f));

    // Then
    glm::vec3 position = transform->getPosition();
    ASSERT_FLOAT_EQ(position.x, 1.0f);
    ASSERT_FLOAT_EQ(position.y, 0.0f);
    ASSERT_FLOAT_EQ(position.z, 0.0f);
}

TEST(transform, rotation) {
    // Given
    std::unique_ptr<Transform> transform = std::make_unique<Transform>();

    // When
    transform->translate(glm::vec3(1.0f, 0.0f, 0.0f));
    transform->rotateGlobal(glm::half_pi<float>());

    // Then
    glm::vec3 position = transform->getPosition();
    ASSERT_NEAR(position.x, 0.0f, glm::epsilon<float>());
    ASSERT_NEAR(position.y, 1.0f, glm::epsilon<float>());
    ASSERT_NEAR(position.z, 0.0f, glm::epsilon<float>());
}

TEST(transform, child_position_is_relative_to_parent_translation) {
    // Given
    std::unique_ptr<Transform> parent = std::make_unique<Transform>();
    std::unique_ptr<Transform> child  = std::make_unique<Transform>(parent.get());

    // When
    parent->translate(glm::vec3(1.0f, 0.0f, 0.0f));

    // Then
    glm::vec3 position = child->getPosition();
    ASSERT_FLOAT_EQ(position.x, 1.0f);
    ASSERT_FLOAT_EQ(position.y, 0.0f);
    ASSERT_FLOAT_EQ(position.z, 0.0f);
}

TEST(transform, child_translation_is_relative_to_parent_translation) {
    // Given
    std::unique_ptr<Transform> parent = std::make_unique<Transform>();
    std::unique_ptr<Transform> child  = std::make_unique<Transform>(parent.get());

    // When
    parent->translate(glm::vec3(1.0f, 0.0f, 0.0f));
    child->translate(glm::vec3(-1.0f, 0.0f, 0.0f));

    // Then
    glm::vec3 position = child->getPosition();
    ASSERT_FLOAT_EQ(position.x, 0.0f);
    ASSERT_FLOAT_EQ(position.y, 0.0f);
    ASSERT_FLOAT_EQ(position.z, 0.0f);
}