#pragma once

#include "engine/components/shader_component.hpp"

class Shader;
class Object;

namespace Engine::Components::Shaders {
    class GenericShaderComponent : public ShaderComponent {
      public:
        GenericShaderComponent(Entity& object, Shader& shader);
        ~GenericShaderComponent() override = default;

        // --- ShaderComponent ---
        auto use() -> void override;

        // --- Component ---
        auto renderConfiguration() -> void override;

      private:
        Shader& m_shader;
    };
}