#pragma once

#include "engine/components/component.hpp"

namespace Engine::Components {
    class Script : public Component {
      public:
        Script(Object& object)
              : Component{object} {};
        ~Script() override = default;

        virtual auto execute(int dt) -> void = 0;
    };
}