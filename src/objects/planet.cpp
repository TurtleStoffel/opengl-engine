#include "objects/planet.hpp"

#include "models/sphere.hpp"

Planet::Planet(GLuint shader, Scene* pScene) {
    _pModel = new Sphere(shader);
    pScene->addRenderable(_pModel);
}

Planet::~Planet() {
    delete _pModel;
}
