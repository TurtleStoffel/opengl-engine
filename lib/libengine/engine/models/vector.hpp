#pragma once

#include <glm/glm.hpp>

#include "model.hpp"

class Vector final : public Model {
  public:
    Vector(const Object& object, glm::vec3 direction);
    ~Vector() override = default;
};