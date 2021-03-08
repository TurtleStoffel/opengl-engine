#pragma once

#include "engine/models/effects/effect.hpp"
#include "engine/opengl.hpp"

#include <functional>
#include <glm/glm.hpp>
#include <memory>
#include <vector>

class ShaderRegistry;
class Object;
class Transform;

struct Vertex {
    glm::vec3 position;
    glm::vec3 normal;
    glm::vec3 color;
};

/**
 * Default shader is low-poly, different shaders can be enabled through Pre Render Logic.
 */
class Model {
  public:
    /**
     * @param parent Game Object that spawned this Model
     */
    Model(const Object& parent);
    virtual ~Model() = default;

    void render(const ShaderRegistry& shaderContainer) const;
    void glDraw() const;

    auto setPreRenderLogic(std::function<void(const ShaderRegistry&)> preRenderLogic) -> void;
    void addPreRenderEffect(std::unique_ptr<Effect> effect);
    void addPostRenderEffect(std::unique_ptr<Effect> effect);
    auto setupBuffers() -> void;

    auto getSelected() const -> bool;

  protected:
    const Object& m_object;

    GLenum m_renderingMode{GL_TRIANGLES};

    std::vector<Vertex> m_vertices;
    std::vector<unsigned int> m_indices;

  private:
    void _generateOpenGLBuffers();
    void _renderSilhouette(const ShaderRegistry& shaderContainer) const;

    std::function<void(const ShaderRegistry&)> m_preRenderLogic;
    std::vector<std::unique_ptr<Effect>> preRenderEffects;
    std::vector<std::unique_ptr<Effect>> m_postRenderEffects;

    GLuint _vertexArrayObject;
    // Vertex Information
    GLuint _vertexBufferObject;
    // Vertex Indices
    GLuint _elementBufferObject;
};