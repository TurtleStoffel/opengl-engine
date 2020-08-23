#pragma once

#include <glm/glm.hpp>

class ShaderContainer;

/**
 * Contains all information about location and orientation of an object, also has the required
 * information to calculate the model matrix
 */
class Transform {
  public:
    Transform() : Transform(nullptr){};
    Transform(Transform* parent) : parent(parent){};

    void scale(glm::vec3 v);
    void translate(glm::vec3 v);
    void rotateLocal(float radians);
    void rotateGlobal(float radians);

    glm::vec3 getPosition() const;
    glm::vec3 getScale() const;

    void passModelMatrixToShader(ShaderContainer* shaderContainer);

  private:
    glm::mat4 calculateModelMatrix() const;

    Transform* parent;

    glm::vec3 _position = glm::vec3(0.0f, 0.0f, 0.0f);
    glm::vec3 _scale    = glm::vec3(1.0f, 1.0f, 1.0f);

    // Local Rotation is around its own center
    float _localRotation = 0.0f;
    // Global Rotation is around the origin
    float _globalRotation = 0.0f;
};