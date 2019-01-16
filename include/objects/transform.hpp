#ifndef TRANSFORM_HPP
#define TRANSFORM_HPP

#include <glm/glm.hpp>

/**
 * Contains all information about location and orientation of an object, also has the required
 * information to calculate the model matrix
 */
class Transform {
   public:
    void scale(glm::vec3 v);
    void translate(glm::vec3 v);
    void rotate(float degrees);

    glm::vec3 getInitialPosition();
    glm::vec3 getPosition();

    void passModelMatrixToShader();

   private:
    glm::mat4 _calculateModelMatrix();

    glm::vec3 _position = glm::vec3(0.0f, 0.0f, 0.0f);
    glm::vec3 _scale    = glm::vec3(1.0f, 1.0f, 1.0f);
    float _rotation     = 0.0f;
};

#endif
