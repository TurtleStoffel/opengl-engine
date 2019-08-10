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
    Model(Transform* pTransform, Property<bool>* selected);
    /**
     * Overloading when the Parent Object is not selectable
     */
    Model(Transform* pTransform);
    /**
     * Overloading when the Model is not linked to a Game Object (for debug purposes)
     *
     * IMPORTANT!: When using this constructor, the Model implementation is responsible to Set and
     * Destroy the Model Transform
     */
    Model();

    virtual ~Model();

    void render();

   protected:
    void _setupBuffers();

    // Pointer to Transform from parent Object (unless Model is not owned by a Game Object
    Transform* _pTransform;

    GLenum _renderingMode = GL_TRIANGLES;

    std::vector<Vertex> _vertices;
    std::vector<unsigned int> _indices;

   private:
    // Vertex Array Object
    GLuint _vao;
    // Vertex Buffer Object (Vertex Information)
    GLuint _vbo;
    // Element Buffer Object (Vertex Indices)
    GLuint _ebo;

    Property<bool>* _selected;
};

#endif
