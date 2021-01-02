#pragma once

#include "engine/models/effects/effect.hpp"
#include "engine/objects/transform.hpp"
#include "engine/opengl.hpp"

#include <glm/glm.hpp>
#include <memory>
#include <vector>

class ShaderContainer;

struct Vertex {
    glm::vec3 position;
    glm::vec3 normal;
    glm::vec3 color;
};

class Model {
  public:
    /**
     * @param transform Transform of Game Object
     */
    Model(const Transform& transform);

    // Not default because otherwise build error for Effect class
    virtual ~Model() = default;

    void render(bool selected, const ShaderContainer& shaderContainer) const;
    void glDraw() const;

    void addPreRenderEffect(std::unique_ptr<Effect> effect);
    void addPostRenderEffect(std::unique_ptr<Effect> effect);
    auto getTransform() const -> const Transform&;
    auto setupBuffers() -> void;

  protected:
    const Transform& m_transform;

    GLenum m_renderingMode{GL_TRIANGLES};

    std::vector<Vertex> m_vertices;
    std::vector<unsigned int> m_indices;

  private:
    void _generateOpenGLBuffers();
    void _renderSilhouette(const ShaderContainer& shaderContainer) const;

    std::vector<std::unique_ptr<Effect>> preRenderEffects;
    std::vector<std::unique_ptr<Effect>> m_postRenderEffects;

    GLuint _vertexArrayObject;
    // Vertex Information
    GLuint _vertexBufferObject;
    // Vertex Indices
    GLuint _elementBufferObject;
};