#include "engine/components/shader.hpp"

#include "imgui.h"

namespace Engine::Components {
    Shader::Shader(Entity& entity, Shaders::Shader& shader)
          : Component{entity, "Generic Shader"}
          , m_shader{shader} {};

    auto Shader::use() -> void {
        m_shader.use();
    }

    auto Shader::renderConfiguration() -> void {
        ImGui::Text("Shader Component");
        if (ImGui::Button("Recompile")) {
            m_shader.recompile();
        }
    }
}