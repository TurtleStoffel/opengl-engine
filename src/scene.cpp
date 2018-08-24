#include "scene.hpp"

#include "application.hpp"
#include "flatcamera.hpp"

#include "models/ground.hpp"

Scene::Scene(Application* pParent) {
    _renderable.push_back(Ground());
    _camera = new FlatCamera(pParent->getShaderID());
}

Scene::~Scene() {
    delete _camera;
}

void Scene::handleInput(SDL_Event event) {
    _camera->handleInput(event);
}

void Scene::update(int t) {
    _camera->update(t);
}

void Scene::render() {
    for (Model model : _renderable) {
        model.render();
    }
}
