#include "engine/models/effects/outline.hpp"

#include "engine/models/model.hpp"
#include "engine/shadercontainer.hpp"

Outline::Outline(const Model& model) : m_model{model} {
}

void Outline::render(bool selected, const ShaderContainer& shaderContainer) const {
    if (selected) {
        // Disable depth test to render to background
        glDisable(GL_DEPTH_TEST);
        shaderContainer.useSilhouetteShader();
        m_model.glDraw();
        glEnable(GL_DEPTH_TEST);
    }
}