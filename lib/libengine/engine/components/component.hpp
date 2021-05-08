#pragma once

#include <string>

namespace Engine {
    class Entity;
}

namespace Engine::Components {
    class Component {
      public:
        Component(Entity& entity, const std::string& m_name);
        virtual ~Component() = default;

        virtual auto renderConfiguration() -> void;

      protected:
        Entity& m_entity;
        std::string m_name;
    };
}