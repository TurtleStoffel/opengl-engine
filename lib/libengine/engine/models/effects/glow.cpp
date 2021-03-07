#include "glow.hpp"

#include "engine/shaders/glowshader.hpp"
#include "engine/shaders/shadercontainer.hpp"

Glow::Glow(const Model& model) : m_model{model} {
}

void Glow::render(const ShaderRegistry& shaderContainer) const {
    glDisable(GL_DEPTH_TEST);
    shaderContainer.get<GlowShader>().use();
    m_model.glDraw();
    glEnable(GL_DEPTH_TEST);
}