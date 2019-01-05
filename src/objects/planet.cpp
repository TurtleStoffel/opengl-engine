#include "objects/planet.hpp"

#include "models/sphere.hpp"

Planet::Planet(Scene* pScene) {
    _pModel = new Sphere(_pTransform);
    pScene->addRenderable(_pModel);

    _pTransform->translate(glm::vec3(3.0f, 0.0f, 0.0f));
}

Planet::~Planet() {
    delete _pModel;
}

void Planet::update(int t) {
    _pTransform->rotate(0.0001f * t);
}
