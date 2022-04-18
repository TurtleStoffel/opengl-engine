#include "engine/components/models/sphere.hpp"

#include "engine/entity/entity.hpp"

#include <glm/gtx/norm.hpp>
#include <math.h>

namespace Engine::Components::Models {
    Sphere::Sphere(Entity& entity, std::function<glm::vec3(float)> colorGenerator, int depth)
          : Model{entity, "Sphere Model"}
          , m_depth{depth}
          , m_colorGenerator{colorGenerator} {
    }

    Sphere::Sphere(Entity& entity,
                   std::function<glm::vec3(float)> colorGenerator,
                   std::function<float(glm::vec3&)> noiseFunction,
                   int depth)
          : Model{entity, "Sphere Model"}
          , m_depth{depth}
          , m_colorGenerator{colorGenerator}
          , m_noiseFunction{noiseFunction} {
    }

    auto Sphere::generateImpl() -> void {
        m_midPointCache.clear();
        m_vertexIndex = 0;

        float d = (1.0f + sqrt(5.0f)) / 2.0f;
        // clang-format off
        createVertex(glm::normalize(glm::vec3(-1.0f,  d, 0.0f)));
        createVertex(glm::normalize(glm::vec3( 1.0f,  d, 0.0f)));
        createVertex(glm::normalize(glm::vec3(-1.0f, -d, 0.0f)));
        createVertex(glm::normalize(glm::vec3( 1.0f, -d, 0.0f)));

        createVertex(glm::normalize(glm::vec3(0.0f, -1.0f,  d)));
        createVertex(glm::normalize(glm::vec3(0.0f,  1.0f,  d)));
        createVertex(glm::normalize(glm::vec3(0.0f, -1.0f, -d)));
        createVertex(glm::normalize(glm::vec3(0.0f,  1.0f, -d)));

        createVertex(glm::normalize(glm::vec3( d, 0.0f, -1.0f)));
        createVertex(glm::normalize(glm::vec3( d, 0.0f,  1.0f)));
        createVertex(glm::normalize(glm::vec3(-d, 0.0f, -1.0f)));
        createVertex(glm::normalize(glm::vec3(-d, 0.0f,  1.0f)));

        std::vector<Face> faces;
        faces.push_back(Face{ 0, 11,  5});
        faces.push_back(Face{ 0,  5,  1});
        faces.push_back(Face{ 0,  1,  7});
        faces.push_back(Face{ 0,  7, 10});
        faces.push_back(Face{ 0, 10, 11});

        faces.push_back(Face{ 1,  5,  9});
        faces.push_back(Face{ 5, 11,  4});
        faces.push_back(Face{11, 10,  2});
        faces.push_back(Face{10,  7,  6});
        faces.push_back(Face{ 7,  1,  8});

        faces.push_back(Face{ 3,  9,  4});
        faces.push_back(Face{ 3,  4,  2});
        faces.push_back(Face{ 3,  2,  6});
        faces.push_back(Face{ 3,  6,  8});
        faces.push_back(Face{ 3,  8,  9});

        faces.push_back(Face{ 4,  9,  5});
        faces.push_back(Face{ 2,  4, 11});
        faces.push_back(Face{ 6,  2, 10});
        faces.push_back(Face{ 8,  6,  7});
        faces.push_back(Face{ 9,  8,  1});
        // clang-format on

        for (int i = 0; i < m_depth; i++) {
            std::vector<Face> newFaces;
            for (Face face : faces) {
                unsigned int a = getMidpoint(face.v1, face.v2);
                unsigned int b = getMidpoint(face.v2, face.v3);
                unsigned int c = getMidpoint(face.v3, face.v1);

                // clang-format off
                newFaces.push_back(Face{face.v1, a, c});
                newFaces.push_back(Face{face.v2, b, a});
                newFaces.push_back(Face{face.v3, c, b});
                newFaces.push_back(Face{a,       b, c});
                // clang-format on
            }

            faces = newFaces;
        }

        for (Face face : faces) {
            auto height1 = glm::length2(m_vertices[face.v1].position);
            auto height2 = glm::length2(m_vertices[face.v2].position);
            auto height3 = glm::length2(m_vertices[face.v3].position);
            if (height1 > height2 && height1 > height3) {
                m_indices.push_back(face.v1);
                m_indices.push_back(face.v2);
                m_indices.push_back(face.v3);
            } else if (height2 > height1 && height2 > height3) {
                m_indices.push_back(face.v2);
                m_indices.push_back(face.v3);
                m_indices.push_back(face.v1);
            } else {
                m_indices.push_back(face.v3);
                m_indices.push_back(face.v1);
                m_indices.push_back(face.v2);
            }
        }
    }

    auto Sphere::getMidpoint(unsigned int p1, unsigned int p2) -> unsigned int {
        // Determine smallest and biggest index
        unsigned long smallIndex, bigIndex;
        if (p1 < p2) {
            smallIndex = p1;
            bigIndex   = p2;
        } else {
            smallIndex = p2;
            bigIndex   = p1;
        }

        // Calculate key in Midpoint Cache and check if point is already calculated
        unsigned long key = (smallIndex << 32) + bigIndex;
        if (m_midPointCache.count(key) == 1) {
            // Vertex has already been calculated before, reuse
            return m_midPointCache.at(key);
        } else {
            // Create new Vertex
            Vertex v1 = m_vertices.at(p1);
            Vertex v2 = m_vertices.at(p2);

            // Calculate midpoint
            glm::vec3 midpoint = glm::normalize(glm::vec3((v1.position.x + v2.position.x) / 2.0f,
                                                          (v1.position.y + v2.position.y) / 2.0f,
                                                          (v1.position.z + v2.position.z) / 2.0f));

            // Create Midpoint Vertex
            unsigned int vertexIndex = createVertex(midpoint);

            // Add Vertex to cache
            m_midPointCache[key] = vertexIndex;

            return vertexIndex;
        }
    }

    auto Sphere::createVertex(glm::vec3 point) -> unsigned int {
        auto normalizedHeight = 0.0f;
        if (m_noiseFunction) {
            normalizedHeight = m_noiseFunction(point);
        }

        // Create Vertex at _vertexIndex
        m_vertices.push_back(Vertex{point, // Position
                                    point, // Normal is equal to Position on a Sphere
                                    m_colorGenerator(normalizedHeight)});

        // Add 1 to _vertexIndex but return pre-incremented value (Value of vertex created in this
        // method)
        return m_vertexIndex++;
    }
}