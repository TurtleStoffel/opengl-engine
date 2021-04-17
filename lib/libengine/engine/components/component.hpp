#pragma once

namespace Engine {
    class Entity;
}

namespace Engine::Components {
    class Component {
      public:
        Component(Entity& entity)
              : m_entity{entity} {};
        virtual ~Component() = default;

        // ImGui visualization
        virtual auto render() -> void{};

      protected:
        Entity& m_entity;
    };
}