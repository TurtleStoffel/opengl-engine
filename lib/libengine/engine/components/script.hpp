#pragma once

#include "engine/components/component.hpp"

#include <string>

namespace Engine::Components {
    class Script : public Component {
      public:
        Script(Entity& object, const std::string& name)
              : Component{object, name} {};
        ~Script() override = default;

        virtual auto execute(int dt) -> void = 0;
    };
}