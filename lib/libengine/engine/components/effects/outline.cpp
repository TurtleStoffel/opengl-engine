#include "engine/components/effects/outline.hpp"

#include "engine/components/model.hpp"
#include "engine/entities/entity.hpp"
#include "engine/shaders/registry.hpp"
#include "engine/shaders/silhouette.hpp"

namespace Engine::Components::Effects {
    Outline::Outline(Entity& entity, Shaders::Registry& shaderRegistry)
          : Effect{entity}
          , m_silhouetteShader(shaderRegistry.getOrCreate<Shaders::Silhouette>()) {
    }

    void Outline::render() const {
        if (m_entity.getRequired<Collider>().getSelected()) {
            // Disable depth test to render to background
            glDisable(GL_DEPTH_TEST);
            m_silhouetteShader.use();
            m_entity.getRequired<Model>().glDraw();
            glEnable(GL_DEPTH_TEST);
        }
    }
}