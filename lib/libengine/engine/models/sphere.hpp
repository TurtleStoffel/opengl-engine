#pragma once

#include <map>

#include "model.hpp"

struct Face {
    unsigned int v1;
    unsigned int v2;
    unsigned int v3;
};

class Sphere : public Model {
  public:
    Sphere(Transform* pTransform);
    Sphere(Transform* pTransform, int depth);
    Sphere(Transform* pTransform, glm::vec3 (*colorGenerator)());
    Sphere(Transform* pTransform, int depth, glm::vec3 (*colorGenerator)());

  private:
    unsigned int _getMidpoint(unsigned int p1, unsigned int p2, glm::vec3 color);
    unsigned int _createVertex(glm::vec3 point, glm::vec3 color);

    // Index + 1 of the last created Vertex
    int _vertexIndex = 0;

    /**
     * unsigned int can define 4.294.967.295 unique points
     * Key formula: (smallIndex << 32) + bigIndex
     * Original Vertices are not added to _midPointCache, so keys are unique
     *      (otherwise smallIndex 0 would lead to existing indices)
     */
    std::map<unsigned long, unsigned int> _midPointCache;
};