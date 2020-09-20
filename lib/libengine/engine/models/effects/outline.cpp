#include "outline.hpp"

#include "shadercontainer.hpp"

void Outline::render(bool selected, const ShaderContainer& shaderContainer) const {
    if (selected) {
        // Disable depth test to render to background
        glDisable(GL_DEPTH_TEST);
        shaderContainer.useSilhouetteShader();
        model.glDraw();
        glEnable(GL_DEPTH_TEST);
    }
}