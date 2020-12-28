#include "glow.hpp"

#include "shadercontainer.hpp"

Glow::Glow(const Model& model) : m_model{model} {
}

void Glow::render([[maybe_unused]] bool selected, const ShaderContainer& shaderContainer) const {
    glDisable(GL_DEPTH_TEST);
    shaderContainer.useGlowShader();
    m_model.glDraw();
    glEnable(GL_DEPTH_TEST);
}