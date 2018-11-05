#include "systemscene.hpp"

#include "flatcamera.hpp"

#include "objects/planet.hpp"
#include "objects/sun.hpp"

SystemScene::SystemScene() {
    _objects.push_back(new Sun(this));
    Planet* planet = new Planet(this);
    planet->translate(glm::vec3(3.0f, 0.0f, 0.0f));
    _objects.push_back(planet);
    _camera = new FlatCamera();
    _camera->set(glm::vec3(0.0f, 0.0f, 5.0f),
                 glm::vec3(0.0f, 0.0f, -1.0f),
                 glm::vec3(0.0f, 1.0f, 0.0f));
}
