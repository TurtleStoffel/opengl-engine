#include "systemscene.hpp"

#include "flatcamera.hpp"

#include "objects/planet.hpp"
#include "objects/sun.hpp"

SystemScene::SystemScene() {
    // Create camera
    _pCamera = FlatCamera::changeInstance();
    _pCamera->set(glm::vec3(0.0f, 0.0f, 5.0f),
                  glm::vec3(0.0f, 0.0f, -1.0f),
                  glm::vec3(0.0f, 1.0f, 0.0f));

    // Create objects
    _objects.push_back(new Sun(this));
    _objects.push_back(new Planet(this));
}
