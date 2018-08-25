#include "scene.hpp"

#include "application.hpp"
#include "camera.hpp"

Scene::~Scene() {
    if (_camera) {
        delete _camera;
    }
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
