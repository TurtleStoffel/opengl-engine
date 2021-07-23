#pragma once

#include "engine/components/component.hpp"
#include "engine/opengl.hpp"

#include <functional>
#include <glm/glm.hpp>
#include <memory>
#include <string>
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
        Model(Entity& entity, const std::string& name);
        ~Model() override = default;

        auto generate() -> void;
        auto render() const -> void;

        auto glDraw() const -> void;

      protected:
        // Fill m_vertices and m_indices.
        virtual auto generateImpl() -> void = 0;

        GLenum m_renderingMode{GL_TRIANGLES};

        std::vector<Vertex> m_vertices;
        std::vector<unsigned int> m_indices;

      private:
        auto generateOpenGLBuffers() -> void;
        auto setupBuffers() -> void;

        GLuint m_vertexArrayObject;
        // Vertex Information
        GLuint m_vertexBufferObject;
        // Vertex Indices
        GLuint m_elementBufferObject;
    };
}