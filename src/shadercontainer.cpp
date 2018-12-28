#include "shadercontainer.hpp"

Shader* ShaderContainer::lowPolyShader = nullptr;

void ShaderContainer::init() {
    lowPolyShader = new Shader("../shaders/low-poly/vertex.glsl",
                               "../shaders/low-poly/geometry.glsl",
                               "../shaders/low-poly/fragment.glsl");
}

void ShaderContainer::destroy() {
    delete lowPolyShader;
}
