#pragma once

#include <glm/glm.hpp>

/**
 * Contains all information about location and orientation of an object, also has the required
 * information to calculate the model matrix
 */
class Transform {
  public:
    void scale(glm::vec3 v);
    void translate(glm::vec3 v);
    void rotateLocal(float degrees);
    void rotateGlobal(float degrees);

    glm::vec3 getInitialPosition();
    glm::vec3 getPosition() const;
    glm::vec3 getScale() const;

    void passModelMatrixToShader();

  private:
    glm::mat4 _calculateModelMatrix() const;

    glm::vec3 _position = glm::vec3(0.0f, 0.0f, 0.0f);
    glm::vec3 _scale    = glm::vec3(1.0f, 1.0f, 1.0f);

    // Local Rotation is around its own center
    float _localRotation = 0.0f;
    // Global Rotation is around the origin
    float _globalRotation = 0.0f;
};