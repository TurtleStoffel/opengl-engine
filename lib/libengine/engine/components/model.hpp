#pragma once

#include "engine/components/component.hpp"
#include "engine/opengl.hpp"

#include <functional>
#include <glm/glm.hpp>
#include <memory>
#include <string>
#include <vector>

namespace Engine {
    class Entity;
}

namespace Engine::Components {
    class Transform;
}

namespace Engine::Components {
    class Model : public Component {
      public:
        Model(Entity& entity, const std::string& name);
        ~Model() override = default;

        auto generate() -> void;
        auto render() const -> void;

        auto glDraw() const -> void;

      protected:
        struct Vertex {
            glm::vec3 position;
            glm::vec3 normal;
            glm::vec3 color;
        };

        GLenum m_renderingMode{GL_TRIANGLES};

        std::vector<Vertex> m_vertices;
        std::vector<unsigned int> m_indices;

      private:
        // Fill m_vertices and m_indices.
        virtual auto generateImpl() -> void = 0;

        auto generateOpenGLBuffers() -> void;
        auto setupBuffers() -> void;

        GLuint m_vertexArrayObject;
        // Vertex Information
        GLuint m_vertexBufferObject;
        // Vertex Indices
        GLuint m_elementBufferObject;
    };
}