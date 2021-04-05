#pragma once

#include "engine/components/shader_component.hpp"

class Shader;
class Object;

namespace Engine::Components::Shaders {
    class GenericShaderComponent : public ShaderComponent {
      public:
        GenericShaderComponent(Object& object, const Shader& shader);
        ~GenericShaderComponent() override = default;

        auto use() -> void override;

      private:
        const Shader& m_shader;
    };
}