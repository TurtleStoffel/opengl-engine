#include "scene.hpp"

#include "application.hpp"
#include "flatcamera.hpp"

#include "models/ground.hpp"
#include "models/sphere.hpp"

#include "objects/planet.hpp"

Scene::Scene(Application* pParent) {
    GLuint shaderID = pParent->getShaderID();
    _objects.push_back(new Planet(shaderID, this));
    _camera = new FlatCamera(shaderID);
}

Scene::~Scene() {
    delete _camera;
    for (Object* object : _objects) {
        delete object;
    }
}

void Scene::handleInput(SDL_Event event) {
    _camera->handleInput(event);
}

void Scene::update(int t) {
    _camera->update(t);
}

void Scene::render() {
    for (Model* model : _renderable) {
        model->render();
    }
}

void Scene::addRenderable(Model* pModel) {
    _renderable.push_back(pModel);
}
