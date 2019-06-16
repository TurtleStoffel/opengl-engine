#include "models/ray.hpp"

#include "color.hpp"
#include "scene.hpp"

Ray::Ray(glm::vec3 p1, glm::vec3 p2) {
    // Set rendering mode to lines for ray, default rendering mode is triangles
    _renderingMode = GL_LINES;

    // Ray is not linked to Game Object, so manages its own Transform
    _pTransform = new Transform();

    // Create two vertices for the start and end point
    _vertices.push_back(Vertex{p1, p1, color::blue()});
    _vertices.push_back(Vertex{p2, p2, color::blue()});

    _setupBuffers();

    Scene::instance()->addRenderable(this);
}

Ray::~Ray() {
    delete _pTransform;
}
