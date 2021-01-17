#include "engine/shaders/lowpolyshader.hpp"

LowPolyShader::LowPolyShader()
    : Shader{"shaders/low-poly/vertex.glsl", "shaders/low-poly/fragment.glsl"} {
}

auto LowPolyShader::setCameraPosition(GLfloat* position) const -> void {
    setUniform3fv("cameraPosition", position);
}