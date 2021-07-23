#include "debug_vectors.hpp"

#include "engine/components/models/model_factory.hpp"
#include "engine/objects/entity.hpp"

namespace Engine::Components::Effects {
    DebugVectors::DebugVectors(Entity& entity)
          : Effect{entity} {
        m_vectors.push_back(
            Models::ModelFactory::make<Models::Vector>(entity, glm::vec3(1.0f, 0.0f, 0.0f)));
        m_vectors.push_back(
            Models::ModelFactory::make<Models::Vector>(entity, glm::vec3(0.0f, 1.0f, 0.0f)));
        m_vectors.push_back(
            Models::ModelFactory::make<Models::Vector>(entity, glm::vec3(0.0f, 0.0f, 1.0f)));
    }

    auto DebugVectors::render([[maybe_unused]] const ShaderRegistry& shaderRegistry) const -> void {
        for (auto& vector : m_vectors) {
            vector->render();
        }
    }
}