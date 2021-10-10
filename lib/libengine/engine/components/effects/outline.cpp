#include "engine/components/effects/outline.hpp"

#include "engine/components/model.hpp"
#include "engine/objects/entity.hpp"
#include "engine/shaderregistry.hpp"
#include "engine/shaders/silhouetteshader.hpp"

namespace Engine::Components::Effects {
    Outline::Outline(Entity& entity)
          : Effect{entity} {
    }

    void Outline::render(ShaderRegistry& shaderRegistry) const {
        if (m_entity.getRequired<Collider>().getSelected()) {
            // Disable depth test to render to background
            glDisable(GL_DEPTH_TEST);
            shaderRegistry.getOrCreate<SilhouetteShader>().use();
            m_entity.getRequired<Model>().glDraw();
            glEnable(GL_DEPTH_TEST);
        }
    }
}