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

   protected:
    void _setupBuffers();

    glm::vec3 _position = glm::vec3(0.0f, 0.0f, 0.0f);
    glm::vec3 _scale    = glm::vec3(1.0f, 1.0f, 1.0f);

    std::vector<Vertex> _vertices;

   private:
    GLuint _modelMatrixUniform;

    GLuint _vao;
    GLuint _vbo;
};

#endif
