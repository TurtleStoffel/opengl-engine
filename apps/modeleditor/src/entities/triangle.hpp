#pragma once

#include "engine/entities/entity.hpp"
#include "engine/shaders/registry.hpp"

#include <memory>

namespace ModelEditor::Entities {
    class Triangle final {
      public:
        static auto createDefault(Engine::Shaders::Registry& shaderRegistry)
            -> std::unique_ptr<Engine::Entity>;
    };
}