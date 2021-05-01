#pragma once

#include "engine/components/model.hpp"

#include <glm/glm.hpp>

namespace Engine {
    class Entity;
}

namespace Engine::Components::Models {
    class Vector final : public Model {
      public:
        Vector(Entity& entity, const glm::vec3& direction);
        ~Vector() override = default;

      private:
        auto generateImpl() -> void override;

        glm::vec3 m_direction;
    };
}