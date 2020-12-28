#include "debug_vectors.hpp"

#include "engine/shadercontainer.hpp"

DebugVectors::DebugVectors(const Model& model) {
    m_vectors.emplace_back(model.getTransform(), glm::vec3(1.0f, 0.0f, 0.0f));
    m_vectors.emplace_back(model.getTransform(), glm::vec3(0.0f, 1.0f, 0.0f));
    m_vectors.emplace_back(model.getTransform(), glm::vec3(0.0f, 0.0f, 1.0f));
}

auto DebugVectors::render(bool selected, const ShaderContainer& shaderContainer) const -> void {
    for (auto& vector : m_vectors) {
        vector.render(selected, shaderContainer);
    }
}