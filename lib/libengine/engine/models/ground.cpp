#include "ground.hpp"

#include "color.hpp"
#include "noise/simplex_noise.hpp"
#include "util.hpp"

Ground::Ground(Transform* pTransform, Property<bool>* selected) : Model(pTransform, selected) {
    Vertex vertexList[_tiles + 1][_tiles + 1];
    for (unsigned int i = 0; i < _tiles + 1; i++) {
        for (unsigned int j = 0; j < _tiles + 1; j++) {
            float x = (-float(_tiles) / 2 + i) * _tileSize;
            float y = (float(_tiles) / 2 - j) * _tileSize;
            float z = SimplexNoise::noise(x * _noiseFactor, y * _noiseFactor) * _maxHeight;
            // Calculate vertex position
            glm::vec3 position        = glm::vec3(x, y, z);
            vertexList[i][j].position = position;
            vertexList[i][j].position = position;

            // Calculate vertex color
            glm::vec3 color;
            if (z < 0.0f) {
                color = color::blue();
            } else {
                color = color::brown();
            }
            vertexList[i][j].color = color;
        }
    }
    for (unsigned int i = 0; i < _tiles; i++) {
        for (unsigned int j = 0; j < _tiles; j++) {
            // clang-format off
            // Generate first triangle
            _vertices.push_back(vertexList[i+0][j+0]);
            _vertices.push_back(vertexList[i+1][j+0]);
            _vertices.push_back(vertexList[i+0][j+1]);

            // Generate second triangle
            _vertices.push_back(vertexList[i+0][j+1]);
            _vertices.push_back(vertexList[i+1][j+0]);
            _vertices.push_back(vertexList[i+1][j+1]);
            // clang-format on
        }
    }

    _setupBuffers();
}
