#include "engine/components/component.hpp"

#include "imgui.h"

namespace Engine::Components {
    Component::Component(Entity& entity, const std::string& name)
          : m_entity{entity}
          , m_name{name} {
    }

    auto Component::renderConfiguration() -> void {
        ImGui::Text("%s", m_name.c_str());
    }
}