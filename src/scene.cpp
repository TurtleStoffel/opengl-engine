#include "scene.hpp"

#include <glm/gtc/matrix_transform.hpp>

#include "application.hpp"
#include "camera.hpp"
#include "objects/collider.hpp"

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
    for (Model* model : _models) {
        model->render();
    }
}

void Scene::addRenderable(Model* pModel) {
    _models.push_back(pModel);
}

void Scene::addCollider(Collider* pCollider) {
    _colliders.push_back(pCollider);
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
        for (Collider* collider : _colliders) {
            // Implemented like this to make selection of closest object in the future easier
            if (collider->intersect(point, direction)) {
                collider->setSelected(true);
            } else {
                collider->setSelected(false);
            }
        }
    }
}
