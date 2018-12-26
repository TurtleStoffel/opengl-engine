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
        // Get coordinates in window space
        int x = event.motion.x;
        int y = event.motion.y;

        glm::mat4 projectionMatrix = _pCamera->_projectionMatrix;
        glm::mat4 viewMatrix       = _pCamera->_viewMatrix;

        int windowWidth;
        int windowHeight;
        _pCamera->getWindowSize(windowWidth, windowHeight);

        // Transform coordinates to world space
        glm::vec3 nearPoint = glm::unProject(glm::vec3(x, y, 0.0),
                                             viewMatrix,
                                             projectionMatrix,
                                             glm::vec4(0.0, 0.0, windowWidth, windowHeight));

        glm::vec3 farPoint = glm::unProject(glm::vec3(x, y, 1.0),
                                            viewMatrix,
                                            projectionMatrix,
                                            glm::vec4(0.0, 0.0, windowWidth, windowHeight));

        for (Model* model : _renderable) {
            if (model->intersect(nearPoint, farPoint - nearPoint)) {
                std::cout << "Intersection with an object!" << std::endl;
            }
        }
    }
}
