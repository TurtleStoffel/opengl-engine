#pragma once

#include "engine/components/shader_component.hpp"

class Shader;
class Object;

namespace Engine::Components::Shaders {
    class GenericShaderComponent : public ShaderComponent {
      public:
        GenericShaderComponent(Object& object, const Shader& shader);
        ~GenericShaderComponent() override = default;

        // --- ShaderComponent ---
        auto use() -> void override;

        // --- Component ---
        auto render() -> void override;

      private:
        const Shader& m_shader;
    };
}