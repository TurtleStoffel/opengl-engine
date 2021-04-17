#pragma once

#include "engine/components/component.hpp"

namespace Engine::Components {
    class GuiComponent : public Component {
      public:
        GuiComponent(Entity& object)
              : Component{object} {};
        ~GuiComponent() override = default;

        auto render() -> void override = 0;
    };
}