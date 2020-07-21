#include "scene/scene.hpp"

#include <glm/gtc/matrix_transform.hpp>

#include "application.hpp"
#include "camera.hpp"
#include "objects/collider.hpp"

Scene::Scene() {
    camera = std::make_unique<Camera>();
}

bool Scene::handleInput(SDL_Event event) {
    if (camera->handleInput(event)) {
        return true;
    }

    // Mousepicking has no impact on return value
    _mousePick(event);

    return false;
}

void Scene::render() {
    for (const std::unique_ptr<Object>& pObject : _objects) {
        pObject->render();
    }

    _renderGui();
}

void Scene::setWindowSize(int windowWidth, int windowHeight) {
    camera->setWindowSize(windowWidth, windowHeight);
}

void Scene::update(int dt) {
    camera->update(dt);

    for (std::unique_ptr<Object>& pObject : _objects) {
        pObject->update(dt);
    }
}

void Scene::_mousePick(SDL_Event event) {
    // Only update if mouse has moved
    if (event.type == SDL_MOUSEMOTION) {
        // Transform point to ray in world space
        glm::vec3 point;
        glm::vec3 direction;
        camera->calculateClickRay(event.motion.x, event.motion.y, point, direction);

        // Check for each object in scene if there was an intersection
        for (std::unique_ptr<Object>& pObject : _objects) {
            pObject->intersect(point, direction);
        }
    }
}
