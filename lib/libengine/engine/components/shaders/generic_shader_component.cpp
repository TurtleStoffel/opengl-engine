#include "engine/components/shaders/generic_shader_component.hpp"

#include "engine/shaders/shader.hpp"

namespace Engine::Components::Shaders {
    GenericShaderComponent::GenericShaderComponent(Object& object, const Shader& shader)
          : ShaderComponent{object}
          , m_shader{shader} {
    }

    auto GenericShaderComponent::use() -> void {
        m_shader.use();
    }
}