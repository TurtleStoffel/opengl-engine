#include "objects/transform.hpp"

#include <glm/gtc/matrix_transform.hpp>

#include "shadercontainer.hpp"

void Transform::scale(glm::vec3 v) {
    _scale *= v;
}

void Transform::translate(glm::vec3 v) {
    _position += v;
}

void Transform::rotate(float degrees) {
    _rotation += degrees;
}

glm::vec3 Transform::getPosition() {
    return _position;
}

void Transform::passModelMatrixToShader() {
    glm::mat4 modelMatrix = glm::rotate(glm::mat4(1.0f), _rotation, glm::vec3(0.0f, 0.0f, 1.0f));
    modelMatrix           = glm::scale(modelMatrix, _scale);
    modelMatrix           = glm::translate(modelMatrix, _position);

    // Apply model transformation matrix
    ShaderContainer::instance()->setModelViewProjectionMatrix(&modelMatrix[0][0], nullptr, nullptr);
}
