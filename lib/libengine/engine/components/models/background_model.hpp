#pragma once

#include "engine/components/model.hpp"

namespace Engine {
    class Entity;
}

namespace Engine::Components::Models {
    class BackgroundModel : public Model {
      public:
        BackgroundModel(Entity& entity);
        ~BackgroundModel() override = default;
    };
}