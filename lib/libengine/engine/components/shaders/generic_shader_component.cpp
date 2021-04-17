#include "engine/components/shaders/generic_shader_component.hpp"

#include "engine/shaders/shader.hpp"

#include "imgui.h"

namespace Engine::Components::Shaders {
    GenericShaderComponent::GenericShaderComponent(Entity& object, Shader& shader)
          : ShaderComponent{object}
          , m_shader{shader} {
    }

    auto GenericShaderComponent::use() -> void {
        m_shader.use();
    }

    auto GenericShaderComponent::render() -> void {
        ImGui::Text("Shader Component");
        if (ImGui::Button("Recompile")) {
            m_shader.recompile();
        }
    }
}