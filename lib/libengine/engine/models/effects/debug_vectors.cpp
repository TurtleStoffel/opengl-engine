#include "debug_vectors.hpp"

#include "engine/models/model_factory.hpp"
#include "engine/objects/object.hpp"
#include "engine/shadercontainer.hpp"

DebugVectors::DebugVectors(const Object& object) {
    m_vectors.push_back(ModelFactory::make<Vector>(object, glm::vec3(1.0f, 0.0f, 0.0f)));
    m_vectors.push_back(ModelFactory::make<Vector>(object, glm::vec3(0.0f, 1.0f, 0.0f)));
    m_vectors.push_back(ModelFactory::make<Vector>(object, glm::vec3(0.0f, 0.0f, 1.0f)));
}

auto DebugVectors::render(bool selected, const ShaderContainer& shaderContainer) const -> void {
    for (auto& vector : m_vectors) {
        vector->render(selected, shaderContainer);
    }
}