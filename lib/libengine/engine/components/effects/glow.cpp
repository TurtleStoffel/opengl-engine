#include "glow.hpp"

#include "engine/components/model.hpp"
#include "engine/entities/entity.hpp"
#include "engine/shaderregistry.hpp"
#include "engine/shaders/glowshader.hpp"

namespace Engine::Components::Effects {
    Glow::Glow(Entity& entity)
          : Effect{entity} {
    }

    void Glow::render(ShaderRegistry& shaderRegistry) const {
        glDisable(GL_DEPTH_TEST);
        shaderRegistry.getOrCreate<GlowShader>().use();
        m_entity.getRequired<Model>().glDraw();
        glEnable(GL_DEPTH_TEST);
    }
}