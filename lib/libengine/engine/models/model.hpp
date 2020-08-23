#pragma once

#include <glm/glm.hpp>
#include <vector>

#include "objects/transform.hpp"
#include "opengl.hpp"

class ShaderContainer;

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

    virtual ~Model() = default;

    void render(bool selected, ShaderContainer* shaderContainer) const;

  protected:
    void _setupBuffers();

    Transform* _pTransform;

    GLenum _renderingMode = GL_TRIANGLES;

    std::vector<Vertex> vertices;
    std::vector<unsigned int> indices;

  private:
    void _generateOpenGLBuffers();
    void _renderSilhouette(ShaderContainer* shaderContainer) const;
    void _renderModel(ShaderContainer* shaderContainer) const;

    GLuint _vertexArrayObject;
    // Vertex Information
    GLuint _vertexBufferObject;
    // Vertex Indices
    GLuint _elementBufferObject;
};