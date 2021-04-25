#pragma once

#include "engine/components/component.hpp"

#include <cassert>
#include <memory>

namespace Engine::Components {
    class GuiComponent : public Component {
      public:
        GuiComponent(Entity& object)
              : Component{object} {};
        ~GuiComponent() override = default;

        virtual auto render() -> void = 0;

        virtual auto addSubcomponent([[maybe_unused]] std::unique_ptr<GuiComponent> subcomponent)
            -> void {
            // This call is only allowed on CompositeGui
            assert(false);
        }
    };
}