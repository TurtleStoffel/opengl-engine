#include "scene.hpp"

#include "models/ground.hpp"

Scene::Scene() {
    _renderable.push_back(Ground());
    //_pModel = new Ground();
}

Scene::~Scene() {
}

void Scene::handleInput(SDL_Event event) {
}

void Scene::render() {
    for (Model model : _renderable) {
        model.render();
    }
    //_pModel->render();
}
