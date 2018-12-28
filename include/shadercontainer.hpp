#ifndef SHADER_CONTAINER_HPP
#define SHADER_CONTAINER_HPP

#include "shader.hpp"

class ShaderContainer {
   public:
    static Shader* lowPolyShader;
    // static Shader* silhouetteShader;

    static void init();
    static void destroy();
};

#endif
