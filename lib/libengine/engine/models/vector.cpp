#include "vector.hpp"

#include "engine/color.hpp"
#include "engine/objects/object.hpp"

Vector::Vector(const Engine::Object& object, glm::vec3 direction)
      : Model{object} {
    m_renderingMode = GL_LINES;

    auto normalizedDirection = glm::normalize(direction);

    auto origin = glm::vec3{0.0f, 0.0f, 0.0f};
    m_vertices.push_back(Vertex{origin, origin, color::blue});
    m_vertices.push_back(
        Vertex{normalizedDirection * 2.0f, normalizedDirection * 2.0f, color::yellow});

    m_indices.push_back(0);
    m_indices.push_back(1);
}