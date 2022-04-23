#pragma once

#include "engine/components/model.hpp"
#include "engine/entities/entity.hpp"

#include <string>

namespace ModelEditor::Models {
    class Triangle final : public Engine::Components::Model {
      public:
        Triangle(Engine::Entity& entity);
        ~Triangle() override = default;

      private:
        auto generateImpl() -> void override;
    };
}