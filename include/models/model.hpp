#ifndef MODEL_HPP
#define MODEL_HPP

#include <glm/glm.hpp>
#include <vector>

#include "opengl.hpp"

struct Vertex {
    glm::vec3 position;
    glm::vec3 color;
};

class Model {
   public:
    Model();
    void render();

   protected:
    void _setupBuffers();

    std::vector<Vertex> _vertices;
    GLuint _vao;
    GLuint _vbo;
};

#endif
