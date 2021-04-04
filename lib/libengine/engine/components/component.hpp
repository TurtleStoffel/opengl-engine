#pragma once

class Object;

namespace Engine::Components {
    class Component {
      public:
        Component(Object& object)
              : m_object{object} {};
        virtual ~Component() = default;

      protected:
        Object& m_object;
    };
}