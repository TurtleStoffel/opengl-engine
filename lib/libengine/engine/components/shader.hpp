#pragma once

#include "engine/components/component.hpp"
#include "engine/shaders/shader.hpp"

#include <string>

namespace Engine::Components {
    /**
     * Component implementation of a Shader. Specialized Shaders with specific configuration can
     * inherit from this implementation to override the renderConfiguration function.
     *
     * The distiction between Shader as a Component and the Shader itself is required to avoid
     * compiling the same Shader multiple times because they are attached as components to different
     * entities.
     */
    class Shader : public Component {
      public:
        Shader(Entity& entity, Shaders::Shader& shader);
        ~Shader() override = default;

        auto use() -> void;

        // --- Component ---
        auto renderConfiguration() -> void override;

      private:
        Shaders::Shader& m_shader;
    };
}
