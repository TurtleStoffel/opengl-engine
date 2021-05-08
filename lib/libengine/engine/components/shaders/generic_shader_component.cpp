#include "engine/components/shaders/generic_shader_component.hpp"

#include "engine/shaders/shader.hpp"

#include "imgui.h"

namespace Engine::Components::Shaders {
    GenericShaderComponent::GenericShaderComponent(Entity& entity, Shader& shader)
          : ShaderComponent{entity, "Generic Shader Component"}
          , m_shader{shader} {
    }

    auto GenericShaderComponent::use() -> void {
        m_shader.use();
    }

    auto GenericShaderComponent::renderConfiguration() -> void {
        ImGui::Text("Shader Component");
        if (ImGui::Button("Recompile")) {
            m_shader.recompile();
        }
    }
}