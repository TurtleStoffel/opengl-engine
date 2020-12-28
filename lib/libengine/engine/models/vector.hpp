#pragma once

#include <glm/glm.hpp>

#include "model.hpp"

class Vector final : public Model {
  public:
    Vector(const Transform& transform, glm::vec3 direction);
    ~Vector() override = default;
};