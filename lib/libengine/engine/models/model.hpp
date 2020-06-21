#pragma once

#include <glm/glm.hpp>
#include <vector>

#include "objects/transform.hpp"
#include "opengl.hpp"

#include "util/property.hpp"

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

    Transform* _pTransform;

    GLenum _renderingMode = GL_TRIANGLES;

    std::vector<Vertex> _vertices;
    std::vector<unsigned int> _indices;

  private:
    void _generateOpenGLBuffers();
    void _renderSilhouette();
    void _renderModel();

    GLuint _vertexArrayObject;
    // Vertex Information
    GLuint _vertexBufferObject;
    // Vertex Indices
    GLuint _elementBufferObject;

    Property<bool>* _selected;
};