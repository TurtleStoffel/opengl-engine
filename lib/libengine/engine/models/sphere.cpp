#include "sphere.hpp"

#include <math.h>

#include "application.hpp"
#include "noise/simplex_noise.hpp"
#include "util.hpp"

Sphere::Sphere(Transform* pTransform, glm::vec3 color, int depth) : Model(pTransform) {
    float d = (1.0f + sqrt(5.0f)) / 2.0f;
    // clang-format off
    _createVertex(glm::normalize(glm::vec3(-1.0f,  d, 0.0f)), color);
    _createVertex(glm::normalize(glm::vec3( 1.0f,  d, 0.0f)), color);
    _createVertex(glm::normalize(glm::vec3(-1.0f, -d, 0.0f)), color);
    _createVertex(glm::normalize(glm::vec3( 1.0f, -d, 0.0f)), color);

    _createVertex(glm::normalize(glm::vec3(0.0f, -1.0f,  d)), color);
    _createVertex(glm::normalize(glm::vec3(0.0f,  1.0f,  d)), color);
    _createVertex(glm::normalize(glm::vec3(0.0f, -1.0f, -d)), color);
    _createVertex(glm::normalize(glm::vec3(0.0f,  1.0f, -d)), color);

    _createVertex(glm::normalize(glm::vec3( d, 0.0f, -1.0f)), color);
    _createVertex(glm::normalize(glm::vec3( d, 0.0f,  1.0f)), color);
    _createVertex(glm::normalize(glm::vec3(-d, 0.0f, -1.0f)), color);
    _createVertex(glm::normalize(glm::vec3(-d, 0.0f,  1.0f)), color);

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

    for (int i = 0; i < depth; i++) {
        std::vector<Face> newFaces;
        for (Face face : faces) {
            unsigned int a = _getMidpoint(face.v1, face.v2, color);
            unsigned int b = _getMidpoint(face.v2, face.v3, color);
            unsigned int c = _getMidpoint(face.v3, face.v1, color);

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
        _indices.push_back(face.v1);
        _indices.push_back(face.v2);
        _indices.push_back(face.v3);
    }

    _setupBuffers();
}

unsigned int Sphere::_getMidpoint(unsigned int p1, unsigned int p2, glm::vec3 color) {
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
    if (_midPointCache.count(key) == 1) {
        // Vertex has already been calculated before, reuse
        return _midPointCache.at(key);
    } else {
        // Create new Vertex
        Vertex v1 = _vertices.at(p1);
        Vertex v2 = _vertices.at(p2);

        // Calculate midpoint
        glm::vec3 midpoint = glm::normalize(glm::vec3((v1.position.x + v2.position.x) / 2.0f,
                                                      (v1.position.y + v2.position.y) / 2.0f,
                                                      (v1.position.z + v2.position.z) / 2.0f));

        // Create Midpoint Vertex
        unsigned int vertexIndex = _createVertex(midpoint, color);

        // Add Vertex to cache
        _midPointCache[key] = vertexIndex;

        return vertexIndex;
    }
}

unsigned int Sphere::_createVertex(glm::vec3 point, glm::vec3 color) {
    float noise = SimplexNoise::noise(point.x * 2.0f, point.y * 2.0f, point.z * 2.0f);

    // Apply noise to the point
    // TODO move offset to variable
    point += 0.05f * noise;

    // Create Vertex at _vertexIndex
    _vertices.push_back(Vertex{
        point, // Position
        point, // Normal is equal to Position on a Sphere
        color  // Color
    });

    // Add 1 to _vertexIndex but return pre-incremented value (Value of vertex created in this
    // method)
    return _vertexIndex++;
}