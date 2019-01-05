#ifndef MODEL_HPP
#define MODEL_HPP

#include <glm/glm.hpp>
#include <vector>

#include "objects/transform.hpp"
#include "opengl.hpp"

struct Vertex {
    glm::vec3 position;
    glm::vec3 normal;
    glm::vec3 color;
};

class Model {
   public:
    /**
     * Create Model and get Transform pointer from parent Object (parent is responsible to destroy
     * the Transform
     */
    Model(Transform* pTransform);
    virtual ~Model();
    void render();

    void setSelected(bool selected);

    /**
     * Return true if ray intersects this model
     */
    virtual bool intersect(glm::vec3 rayPosition, glm::vec3 rayDirection) = 0;

   protected:
    void _setupBuffers();

    /**
     * Pointer to Transform from parent Object
     */
    Transform* _pTransform;

    std::vector<Vertex> _vertices;

   private:
    GLuint _vao;
    GLuint _vbo;

    bool _selected = false;
};

#endif
