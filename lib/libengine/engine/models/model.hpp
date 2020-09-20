#pragma once

#include <glm/glm.hpp>
#include <memory>
#include <vector>

#include "objects/transform.hpp"
#include "opengl.hpp"

class ShaderContainer;
class Effect;

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

    // Not default because otherwise build error for Effect class
    virtual ~Model();

    void render(bool selected, const ShaderContainer& shaderContainer) const;
    void glDraw() const;

    void addEffect(std::unique_ptr<Effect> effect);

  protected:
    void _setupBuffers();

    Transform* _pTransform;

    GLenum _renderingMode = GL_TRIANGLES;

    std::vector<Vertex> vertices;
    std::vector<unsigned int> indices;

  private:
    void _generateOpenGLBuffers();
    void _renderSilhouette(const ShaderContainer& shaderContainer) const;

    std::vector<std::unique_ptr<Effect>> preRenderEffects;

    GLuint _vertexArrayObject;
    // Vertex Information
    GLuint _vertexBufferObject;
    // Vertex Indices
    GLuint _elementBufferObject;
};