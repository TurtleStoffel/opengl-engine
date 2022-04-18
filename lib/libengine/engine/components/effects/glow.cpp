#include "glow.hpp"

#include "engine/components/model.hpp"
#include "engine/entities/entity.hpp"
#include "engine/shaders/glow.hpp"
#include "engine/shaders/registry.hpp"

namespace Engine::Components::Effects {
    Glow::Glow(Entity& entity)
          : Effect{entity} {
    }

    void Glow::render(Shaders::Registry& shaderRegistry) const {
        glDisable(GL_DEPTH_TEST);
        shaderRegistry.getOrCreate<Shaders::Glow>().use();
        m_entity.getRequired<Model>().glDraw();
        glEnable(GL_DEPTH_TEST);
    }
}