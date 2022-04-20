#include "glow.hpp"

#include "engine/components/model.hpp"
#include "engine/entities/entity.hpp"
#include "engine/shaders/registry.hpp"

namespace Engine::Components::Effects {
    Glow::Glow(Entity& entity, Shaders::Registry& shaderRegistry)
          : Effect{entity}
          , m_glowShader{shaderRegistry.getOrCreate<Shaders::Glow>()} {
    }

    void Glow::render() const {
        glDisable(GL_DEPTH_TEST);
        m_glowShader.use();
        m_entity.getRequired<Model>().glDraw();
        glEnable(GL_DEPTH_TEST);
    }
}