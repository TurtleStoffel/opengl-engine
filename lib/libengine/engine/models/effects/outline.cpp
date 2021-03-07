#include "engine/models/effects/outline.hpp"

#include "engine/models/model.hpp"
#include "engine/shaders/shadercontainer.hpp"
#include "engine/shaders/silhouetteshader.hpp"

Outline::Outline(const Model& model) : m_model{model} {
}

void Outline::render(const ShaderRegistry& shaderContainer) const {
    if (m_model.getSelected()) {
        // Disable depth test to render to background
        glDisable(GL_DEPTH_TEST);
        shaderContainer.get<SilhouetteShader>().use();
        m_model.glDraw();
        glEnable(GL_DEPTH_TEST);
    }
}