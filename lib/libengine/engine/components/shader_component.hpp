#pragma once

#include "engine/components/component.hpp"

namespace Engine::Components {
    class ShaderComponent : public Component {
      public:
        ShaderComponent(Object& object)
              : Component{object} {};
        ~ShaderComponent() override = default;

        virtual auto use() -> void = 0;
    };
}
