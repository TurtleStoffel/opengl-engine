#pragma once

#include "engine/components/component.hpp"

#include <string>

namespace Engine::Components {
    class ShaderComponent : public Component {
      public:
        ShaderComponent(Entity& object, const std::string& name)
              : Component{object, name} {};
        ~ShaderComponent() override = default;

        virtual auto use() -> void = 0;
    };
}
