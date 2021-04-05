#pragma once

class Object;

namespace Engine::Components {
    class Component {
      public:
        Component(Object& object)
              : m_object{object} {};
        virtual ~Component() = default;

        // ImGui visualization
        virtual auto render() -> void = 0;

      protected:
        Object& m_object;
    };
}