#pragma once

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
     * @param pTransform Pointer to Transform of Game Object
     */
    Model(Transform* pTransform);
    /**
     * Default Constructor for debugging objects (that are not attached to a Game Object)
     */
    Model();

    virtual ~Model(){};

    void render(bool selected) const;

  protected:
    void _setupBuffers();

    Transform* _pTransform;

    GLenum _renderingMode = GL_TRIANGLES;

    std::vector<Vertex> _vertices;
    std::vector<unsigned int> _indices;

  private:
    void _generateOpenGLBuffers();
    void _renderSilhouette() const;
    void _renderModel() const;

    GLuint _vertexArrayObject;
    // Vertex Information
    GLuint _vertexBufferObject;
    // Vertex Indices
    GLuint _elementBufferObject;
};