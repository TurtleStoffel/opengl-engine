#include "scene.hpp"

#include "application.hpp"
#include "flatcamera.hpp"

#include "models/ground.hpp"

Scene::Scene(Application* parent) {
    _renderable.push_back(Ground());
    _camera = new FlatCamera(parent->getShaderID());
}

void Scene::handleInput(SDL_Event event) {
    _camera->handleInput(event);
}

void Scene::update() {
    _camera->update();
}

void Scene::render() {
    for (Model model : _renderable) {
        model.render();
    }
}
