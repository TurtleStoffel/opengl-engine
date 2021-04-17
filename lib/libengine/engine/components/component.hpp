#pragma once

namespace Engine {
    class Entity;
}

namespace Engine::Components {
    class Component {
      public:
        Component(Entity& object)
              : m_object{object} {};
        virtual ~Component() = default;

        // ImGui visualization
        virtual auto render() -> void{};

      protected:
        Entity& m_object;
    };
}