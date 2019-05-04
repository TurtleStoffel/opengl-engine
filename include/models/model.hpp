#ifndef MODEL_HPP
#define MODEL_HPP

#include <glm/glm.hpp>
#include <vector>

#include "objects/transform.hpp"
#include "opengl.hpp"
#include "property.hpp"

struct Vertex {
    glm::vec3 position;
    glm::vec3 normal;
    glm::vec3 color;
};

class Model {
   public:
    /**
     * Create Model with Transform pointer and selected Boolean Property from parent Object because
     * this is state that always has to be shared between GameObject and Model (parent
     * is responsible to destroy the Transform)
     */
    Model(Transform* pTransform, Property<bool> selected);
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

    Property<bool> _selected;
};

#endif
