#include "scene.hpp"

#include <glm/gtc/matrix_transform.hpp>
#include <iostream>

#include "application.hpp"
#include "camera.hpp"

Scene::~Scene() {
    for (Object* pObject : _objects) {
        delete pObject;
    }
}

void Scene::handleInput(SDL_Event event) {
    // ---Camera Update---
    _pCamera->handleInput(event);

    // ---Mouse Picking Objects---
    _mousePick(event);
}

void Scene::render() {
    for (Model* model : _renderable) {
        model->render();
    }
}

void Scene::addRenderable(Model* pModel) {
    _renderable.push_back(pModel);
}

void Scene::update(int t) {
    _pCamera->update(t);

    for (Object* pObject : _objects) {
        pObject->update(t);
    }
}

void Scene::_mousePick(SDL_Event event) {
    // Only update if mouse has moved
    if (event.type == SDL_MOUSEMOTION) {
        // Transform point to ray in world space
        glm::vec3 point;
        glm::vec3 direction;
        _pCamera->calculateClickRay(event.motion.x, event.motion.y, point, direction);

        for (Model* model : _renderable) {
            if (model->intersect(point, direction)) {
                std::cout << "Intersection with an object!" << std::endl;
            }
        }
    }
}
