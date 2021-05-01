#include "engine/components/model.hpp"

#include "engine/components/collider.hpp"
#include "engine/components/shader_component.hpp"
#include "engine/components/transform.hpp"
#include "engine/models/effects/effect.hpp"
#include "engine/objects/entity.hpp"
#include "engine/opengl.hpp"
#include "engine/shaders/shaderregistry.hpp"

namespace Engine::Components {
    Model::Model(Entity& entity)
          : Component{entity} {
        generateOpenGLBuffers();
    }

    auto Model::generate() -> void {
        m_vertices.clear();
        m_indices.clear();

        generateImpl();

        setupBuffers();
    }

    auto Model::generateOpenGLBuffers() -> void {
        glGenVertexArrays(1, &m_vertexArrayObject);
        glGenBuffers(1, &m_vertexBufferObject);
        glGenBuffers(1, &m_elementBufferObject);
    }

    auto Model::render(const ShaderRegistry& shaderContainer) const -> void {
        glBindVertexArray(m_vertexArrayObject);

        for (const auto& effect : m_preRenderEffects) {
            effect->render(shaderContainer);
        }

        m_entity.get<Engine::Components::ShaderComponent>()->use();

        glDrawElements(m_renderingMode, m_indices.size(), GL_UNSIGNED_INT, 0);

        for (const auto& effect : m_postRenderEffects) {
            effect->render(shaderContainer);
        }

        glBindVertexArray(0);
    }

    auto Model::glDraw() const -> void {
        glDrawElements(m_renderingMode, m_indices.size(), GL_UNSIGNED_INT, 0);
    }

    auto Model::addPreRenderEffect(std::unique_ptr<Effect> effect) -> void {
        m_preRenderEffects.push_back(std::move(effect));
    }

    auto Model::addPostRenderEffect(std::unique_ptr<Effect> effect) -> void {
        m_postRenderEffects.push_back(std::move(effect));
    }

    auto Model::setupBuffers() -> void {
        // Enable model VAO to store Buffer Objects
        glBindVertexArray(m_vertexArrayObject);
        // clang-format off
        /********** VBO **********/
        // Enable VBO
        glBindBuffer(GL_ARRAY_BUFFER, m_vertexBufferObject);
        // Upload Vertex Data
        glBufferData(GL_ARRAY_BUFFER, m_vertices.size() * sizeof(Vertex), &m_vertices[0], GL_STATIC_DRAW);

        // Get attribute information from vertices
        glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)0);
        glEnableVertexAttribArray(0);
        glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)offsetof(Vertex, normal));
        glEnableVertexAttribArray(1);
        glVertexAttribPointer(2, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)offsetof(Vertex, color));
        glEnableVertexAttribArray(2);
        // Disable VBO
        glBindBuffer(GL_ARRAY_BUFFER, 0);
        /********** VBO **********/

        /********** EBO **********/
        // Enable EBO
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_elementBufferObject);
        // Upload Index Data
        glBufferData(GL_ELEMENT_ARRAY_BUFFER, m_indices.size() * sizeof(unsigned int), &m_indices[0], GL_STATIC_DRAW);
        /********** EBO **********/

        // clang-format on
        // Disable VAO
        glBindVertexArray(0);

        // Disable EBO (AFTER VAO has been unbinded, otherwise they are not linked anymore)
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
    }

    auto Model::getSelected() const -> bool {
        auto collider = m_entity.get<Engine::Components::Collider>();
        if (collider) {
            return collider->getSelected();
        } else {
            return false;
        }
    }
}
