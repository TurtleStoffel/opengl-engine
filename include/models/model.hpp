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

    virtual bool intersect(glm::vec3 rayPosition, glm::vec3 rayDirection) = 0;

    // Transformable Interface
    virtual void scale(glm::vec3 v);
    virtual void translate(glm::vec3 v);
    virtual void rotate(float degrees);

   protected:
    void _setupBuffers();

    glm::vec3 _position = glm::vec3(0.0f, 0.0f, 0.0f);
    glm::vec3 _scale    = glm::vec3(1.0f, 1.0f, 1.0f);
    float _rotation     = 0.0f;

    std::vector<Vertex> _vertices;

   private:
    GLuint _modelMatrixUniform;

    GLuint _vao;
    GLuint _vbo;
};

#endif
