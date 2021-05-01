#include "debug_vectors.hpp"

#include "engine/components/models/model_factory.hpp"
#include "engine/objects/entity.hpp"

DebugVectors::DebugVectors(Engine::Entity& object) {
    m_vectors.push_back(Engine::Components::Models::ModelFactory::make<
                        Engine::Components::Models::Vector>(object, glm::vec3(1.0f, 0.0f, 0.0f)));
    m_vectors.push_back(Engine::Components::Models::ModelFactory::make<
                        Engine::Components::Models::Vector>(object, glm::vec3(0.0f, 1.0f, 0.0f)));
    m_vectors.push_back(Engine::Components::Models::ModelFactory::make<
                        Engine::Components::Models::Vector>(object, glm::vec3(0.0f, 0.0f, 1.0f)));
}

auto DebugVectors::render(const ShaderRegistry& shaderContainer) const -> void {
    for (auto& vector : m_vectors) {
        vector->render(shaderContainer);
    }
}