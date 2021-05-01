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

        auto generate() -> void;
        auto render(const ShaderRegistry& shaderContainer) const -> void;

        auto glDraw() const -> void;

        auto addPreRenderEffect(std::unique_ptr<Effect> effect) -> void;
        auto addPostRenderEffect(std::unique_ptr<Effect> effect) -> void;

        auto getSelected() const -> bool;

      protected:
        // Fill m_vertices and m_indices.
        virtual auto generateImpl() -> void = 0;

        GLenum m_renderingMode{GL_TRIANGLES};

        std::vector<Vertex> m_vertices;
        std::vector<unsigned int> m_indices;

      private:
        auto generateOpenGLBuffers() -> void;
        auto setupBuffers() -> void;

        std::vector<std::unique_ptr<Effect>> m_preRenderEffects;
        std::vector<std::unique_ptr<Effect>> m_postRenderEffects;

        GLuint m_vertexArrayObject;
        // Vertex Information
        GLuint m_vertexBufferObject;
        // Vertex Indices
        GLuint m_elementBufferObject;
    };
}