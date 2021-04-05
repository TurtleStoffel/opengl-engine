#pragma once

#include <glm/glm.hpp>

#include "model.hpp"

namespace Engine {
    class Object;
}

class Vector final : public Model {
  public:
    Vector(const Engine::Object& object, glm::vec3 direction);
    ~Vector() override = default;
};