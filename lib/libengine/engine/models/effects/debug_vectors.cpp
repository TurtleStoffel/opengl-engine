#include "debug_vectors.hpp"

#include "engine/models/model_factory.hpp"
#include "engine/objects/object.hpp"

DebugVectors::DebugVectors(const Object& object) {
    m_vectors.push_back(ModelFactory::make<Vector>(object, glm::vec3(1.0f, 0.0f, 0.0f)));
    m_vectors.push_back(ModelFactory::make<Vector>(object, glm::vec3(0.0f, 1.0f, 0.0f)));
    m_vectors.push_back(ModelFactory::make<Vector>(object, glm::vec3(0.0f, 0.0f, 1.0f)));
}

auto DebugVectors::render(const ShaderRegistry& shaderContainer) const -> void {
    for (auto& vector : m_vectors) {
        vector->render(shaderContainer);
    }
}