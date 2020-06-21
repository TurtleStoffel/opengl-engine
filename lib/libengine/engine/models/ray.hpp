#pragma once

#include <glm/glm.hpp>

#include "model.hpp"

/**
 * Debug Model implementation for Ray, which is not linked to a Game Object
 */
// TODO Broken because of Indexed Rendering
class Ray : public Model {
  public:
    /**
     * Debug Implementation of the Ray model creates its own Transform, which is normally owned by
     * the Game Object
     */
    Ray(glm::vec3 p1, glm::vec3 p2);

    ~Ray();
};