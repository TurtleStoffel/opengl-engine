#pragma once

#include <string>

namespace Engine {
    class Entity; // Required forward declare because of circular dependency with component
}

namespace Engine::Components {
    class Component {
      public:
        Component(Entity& entity, const std::string& m_name);
        virtual ~Component() = default;

        Component(const Component&) = delete;
        auto operator=(const Component&) -> Component& = delete;

        virtual auto renderConfiguration() -> void;

      protected:
        Entity& m_entity;
        std::string m_name;
    };
}