#include "scene.hpp"

#include <glm/gtc/matrix_transform.hpp>
#include <iostream>

#include "application.hpp"
#include "camera.hpp"

Scene* Scene::_pScene = nullptr;

Scene::~Scene() {
    for (Object* pObject : _objects) {
        delete pObject;
    }
}

Scene* Scene::instance() {
    assert(_pScene);

    return _pScene;
}

bool Scene::handleInput(SDL_Event event) {
    // ---Camera Update---
    if (_pCamera->handleInput(event)) {
        return true;
    }
    // Camera has precedence over Mouse Picking and Mousepicking has no impact on return value
    else {
        // ---Mouse Picking Objects---
        _mousePick(event);
    }

    return false;
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

Scene::Scene() {
    // Empty constructor
}

void Scene::_mousePick(SDL_Event event) {
    // Only update if mouse has moved
    if (event.type == SDL_MOUSEMOTION) {
        // Transform point to ray in world space
        glm::vec3 point;
        glm::vec3 direction;
        _pCamera->calculateClickRay(event.motion.x, event.motion.y, point, direction);

        // Check for each object in scene if there was an intersection
        for (Model* model : _renderable) {
            if (model->intersect(point, direction)) {
                model->setSelected(true);
            } else {
                model->setSelected(false);
            }
        }
    }
}
