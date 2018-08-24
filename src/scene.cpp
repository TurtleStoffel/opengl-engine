#include "scene.hpp"

#include "application.hpp"
#include "flatcamera.hpp"

#include "models/ground.hpp"

Scene::Scene(Application* pParent) {
    GLuint shaderID = pParent->getShaderID();
    _renderable.push_back(new Ground(shaderID));
    _camera = new FlatCamera(shaderID);
}

Scene::~Scene() {
    delete _camera;
    for (Model* model : _renderable) {
        delete model;
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
