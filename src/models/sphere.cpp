#include "models/sphere.hpp"

#include <math.h>

Sphere::Sphere(GLuint shader) : Sphere(shader, 3) {
}

Sphere::Sphere(GLuint shader, int depth) : Model(shader) {
    float d = (1.0f + sqrt(5.0f)) / 2.0f;

    // clang-format off
    Vertex v1  = {glm::normalize(glm::vec3(-1.0f,  d, 0.0f)), glm::vec3(1.0f, 1.0f, 1.0f)};
    Vertex v2  = {glm::normalize(glm::vec3( 1.0f,  d, 0.0f)), glm::vec3(1.0f, 1.0f, 1.0f)};
    Vertex v3  = {glm::normalize(glm::vec3(-1.0f, -d, 0.0f)), glm::vec3(1.0f, 1.0f, 1.0f)};
    Vertex v4  = {glm::normalize(glm::vec3( 1.0f, -d, 0.0f)), glm::vec3(1.0f, 1.0f, 1.0f)};

    Vertex v5  = {glm::normalize(glm::vec3(0.0f, -1.0f,  d)), glm::vec3(1.0f, 1.0f, 1.0f)};
    Vertex v6  = {glm::normalize(glm::vec3(0.0f,  1.0f,  d)), glm::vec3(1.0f, 1.0f, 1.0f)};
    Vertex v7  = {glm::normalize(glm::vec3(0.0f, -1.0f, -d)), glm::vec3(1.0f, 1.0f, 1.0f)};
    Vertex v8  = {glm::normalize(glm::vec3(0.0f,  1.0f, -d)), glm::vec3(1.0f, 1.0f, 1.0f)};

    Vertex v9  = {glm::normalize(glm::vec3( d, 0.0f, -1.0f)), glm::vec3(1.0f, 1.0f, 1.0f)};
    Vertex v10 = {glm::normalize(glm::vec3( d, 0.0f,  1.0f)), glm::vec3(1.0f, 1.0f, 1.0f)};
    Vertex v11 = {glm::normalize(glm::vec3(-d, 0.0f, -1.0f)), glm::vec3(1.0f, 1.0f, 1.0f)};
    Vertex v12 = {glm::normalize(glm::vec3(-d, 0.0f,  1.0f)), glm::vec3(1.0f, 1.0f, 1.0f)};

    std::vector<Face> faces;
    faces.push_back(Face{v1,  v12, v6 });
    faces.push_back(Face{v1,  v6,  v2 });
    faces.push_back(Face{v1,  v2,  v8 });
    faces.push_back(Face{v1,  v8,  v11});
    faces.push_back(Face{v1,  v11, v12});

    faces.push_back(Face{v2,  v6,  v10});
    faces.push_back(Face{v6,  v12, v5 });
    faces.push_back(Face{v12, v11, v3 });
    faces.push_back(Face{v11, v8,  v7 });
    faces.push_back(Face{v8,  v2,  v9 });

    faces.push_back(Face{v4,  v10, v5 });
    faces.push_back(Face{v4,  v5,  v3 });
    faces.push_back(Face{v4,  v3,  v7 });
    faces.push_back(Face{v4,  v7,  v9 });
    faces.push_back(Face{v4,  v9,  v10});

    faces.push_back(Face{v5,  v10, v6 });
    faces.push_back(Face{v3,  v5,  v12});
    faces.push_back(Face{v7,  v3,  v11});
    faces.push_back(Face{v9,  v7,  v8 });
    faces.push_back(Face{v10, v9,  v2 });
    // clang-format on

    for (int i = 0; i < depth; i++) {
        std::vector<Face> newFaces;
        for (Face face : faces) {
            Vertex a = _getMidpoint(face.v1, face.v2);
            Vertex b = _getMidpoint(face.v2, face.v3);
            Vertex c = _getMidpoint(face.v3, face.v1);

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
        _vertices.push_back(face.v1);
        _vertices.push_back(face.v2);
        _vertices.push_back(face.v3);
    }

    _setupBuffers();
}

Vertex Sphere::_getMidpoint(Vertex p1, Vertex p2) {
    glm::vec3 midpoint = glm::normalize(glm::vec3((p1.position.x + p2.position.x) / 2.0f,
                                                  (p1.position.y + p2.position.y) / 2.0f,
                                                  (p1.position.z + p2.position.z) / 2.0f));
    return Vertex{midpoint, glm::vec3(1.0f, 1.0f, 1.0f)};
}
