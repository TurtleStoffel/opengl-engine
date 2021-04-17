#pragma once

#include <glm/glm.hpp>

#include "model.hpp"

namespace Engine {
    class Entity;
}

class Vector final : public Model {
  public:
    Vector(const Engine::Entity& object, glm::vec3 direction);
    ~Vector() override = default;
};