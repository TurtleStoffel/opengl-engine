#include "engine/scene/scene.hpp"

#include "engine/application.hpp"
#include "engine/camera.hpp"
#include "engine/objects/collider.hpp"

#include <glm/gtc/matrix_transform.hpp>

Scene::Scene() {
    camera = std::make_unique<Camera>();
}

void Scene::update(int dt, const ShaderContainer& shaderContainer) {
    camera->update(dt, shaderContainer);

    for (auto& pObject : m_objects) {
        pObject->update(dt);
    }
}

void Scene::render(const ShaderContainer& shaderContainer) {
    for (auto& pObject : m_objects) {
        pObject->render(shaderContainer);
    }

    _renderGui();
}

bool Scene::handleInput(SDL_Event event) {
    if (camera->handleInput(event)) {
        return true;
    }

    // Mousepicking has no impact on return value
    _mousePick(event);

    return false;
}

void Scene::setWindowSize(int windowWidth, int windowHeight) {
    camera->setWindowSize(windowWidth, windowHeight);
}

void Scene::_mousePick(SDL_Event event) {
    // Only update if mouse has moved
    if (event.type == SDL_MOUSEMOTION) {
        // Transform point to ray in world space
        glm::vec3 point;
        glm::vec3 direction;
        camera->calculateClickRay(event.motion.x, event.motion.y, point, direction);

        // Check for each object in scene if there was an intersection
        for (auto& object : m_objects) {
            object->intersect(point, direction);
        }
    }
}
