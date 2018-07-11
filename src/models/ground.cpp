#include "models/ground.hpp"
#include "util.hpp"
#include "color.hpp"

Ground::Ground() {
    Vertex vertexList[_tiles + 1][_tiles + 1];
    for (int i = 0; i < _tiles + 1; i++) {
        for (int j = 0; j < _tiles + 1; j++) {
            float x = (-float(_tiles) / 2 + i) * _tileSize;
            float y = (float(_tiles) / 2 - j) * _tileSize;
            // Calculate vertex position
            glm::vec3 position = glm::vec3(x, y, util::randf(0.0f, 1.0f));
            vertexList[i][j].position = position;
            vertexList[i][j].position = position;

            // Calculate vertex color
            glm::vec3 color = color::brown();
            vertexList[i][j].color = color;
        }
    }
    for (int i = 0; i < _tiles; i++) {
        for (int j = 0; j < _tiles; j++) {
            // clang-format off
            // Generate first triangle
            _vertices.push_back(vertexList[i+0][j+0]);
            _vertices.push_back(vertexList[i+1][j+0]);
            _vertices.push_back(vertexList[i+0][j+1]);

            // Generate second triangle
            _vertices.push_back(vertexList[i+0][j+1]);
            _vertices.push_back(vertexList[i+1][j+1]);
            _vertices.push_back(vertexList[i+1][j+0]);
            // clang-format on
        }
    }

    _setupBuffers();
}
