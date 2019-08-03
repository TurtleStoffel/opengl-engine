#include "scene.hpp"

#include <glm/gtc/matrix_transform.hpp>

#include "application.hpp"
#include "camera.hpp"
#include "objects/collider.hpp"

Scene::Scene() {
    // Empty Constructor
}

Scene::~Scene() {
    for (Object* pObject : _objects) {
        delete pObject;
    }
}

bool Scene::handleInput(SDL_Event event) {
    // ---Mouse Picking Objects---
    // Mousepicking has no impact on return value
    _mousePick(event);

    // TODO handle other events in the scene

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
        Application::instance()->getCamera()->calculateClickRay(event.motion.x,
                                                                event.motion.y,
                                                                point,
                                                                direction);

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
