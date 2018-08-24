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
    Model(GLuint shader);
    void render();

    glm::vec3 getPosition();

   protected:
    void _setupBuffers();

    glm::vec3 _position = glm::vec3(0.0f, 0.0f, 0.0f);
    GLuint _modelMatrixUniform;

    std::vector<Vertex> _vertices;
    GLuint _vao;
    GLuint _vbo;
};

#endif
