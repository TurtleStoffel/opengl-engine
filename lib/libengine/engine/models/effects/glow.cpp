#include "glow.hpp"

#include "shadercontainer.hpp"

void Glow::render([[maybe_unused]] bool selected, const ShaderContainer& shaderContainer) const {
    glDisable(GL_DEPTH_TEST);
    shaderContainer.getGlowShader()->use();
    model.glDraw();
    glEnable(GL_DEPTH_TEST);
}