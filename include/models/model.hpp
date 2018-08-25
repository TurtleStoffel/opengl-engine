#ifndef MODEL_HPP
#define MODEL_HPP

#include <glm/glm.hpp>
#include <vector>

#include "opengl.hpp"

#include "interfaces/transformable.hpp"

struct Vertex {
    glm::vec3 position;
    glm::vec3 color;
};

class Model : public Transformable {
   public:
    Model();
    virtual ~Model();
    void render();

    // Transformable Interface
    virtual void scale(glm::vec3 v);
    virtual void translate(glm::vec3 v);
    virtual void rotate(glm::vec3 v);

   protected:
    void _setupBuffers();

    glm::vec3 _position = glm::vec3(0.0f, 0.0f, 0.0f);
    glm::vec3 _scale    = glm::vec3(1.0f, 1.0f, 1.0f);
    glm::vec3 _rotation = glm::vec3(0.0f, 0.0f, 0.0f);

    std::vector<Vertex> _vertices;

   private:
    GLuint _modelMatrixUniform;

    GLuint _vao;
    GLuint _vbo;
};

#endif
