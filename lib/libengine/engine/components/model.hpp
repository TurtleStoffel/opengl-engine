#pragma once

#include "engine/components/component.hpp"
#include "engine/models/effects/effect.hpp"
#include "engine/opengl.hpp"

#include <functional>
#include <glm/glm.hpp>
#include <memory>
#include <vector>

class ShaderRegistry;

namespace Engine {
    class Entity;
}

namespace Engine::Components {
    class Transform;
}

struct Vertex {
    glm::vec3 position;
    glm::vec3 normal;
    glm::vec3 color;
};

namespace Engine::Components {
    class Model : public Component {
      public:
        Model(Entity& entity);
        ~Model() override = default;

        void render(const ShaderRegistry& shaderContainer) const;
        void glDraw() const;

        void addPreRenderEffect(std::unique_ptr<Effect> effect);
        void addPostRenderEffect(std::unique_ptr<Effect> effect);
        // Has to be called after m_vertices and m_indices are filled in
        auto setupBuffers() -> void;

        auto getSelected() const -> bool;

      protected:
        GLenum m_renderingMode{GL_TRIANGLES};

        std::vector<Vertex> m_vertices;
        std::vector<unsigned int> m_indices;

      private:
        void _generateOpenGLBuffers();
        void _renderSilhouette(const ShaderRegistry& shaderContainer) const;

        std::vector<std::unique_ptr<Effect>> preRenderEffects;
        std::vector<std::unique_ptr<Effect>> m_postRenderEffects;

        GLuint _vertexArrayObject;
        // Vertex Information
        GLuint _vertexBufferObject;
        // Vertex Indices
        GLuint _elementBufferObject;
    };
}