#include "engine/shaders/lowpolyshader.hpp"

LowPolyShader::LowPolyShader()
      : Engine::Shader{"shaders/low-poly/vertex.glsl", "shaders/low-poly/fragment.glsl"} {
}