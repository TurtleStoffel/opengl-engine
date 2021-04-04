#pragma once

#include "engine/components/component.hpp"

namespace Engine::Components::UpdateScripts {
    class UpdateScript : public Component {
      public:
        UpdateScript(Object& object)
              : Component{object} {};
        ~UpdateScript() override = default;

        virtual auto update(int dt) -> void = 0;
    };
}