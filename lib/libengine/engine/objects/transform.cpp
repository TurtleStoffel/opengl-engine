#include "transform.hpp"

#define GLM_ENABLE_EXPERIMENTAL
#include <glm/gtx/transform.hpp>

#include "shadercontainer.hpp"

void Transform::scale(glm::vec3 v) {
    _scale *= v;
}

void Transform::translate(glm::vec3 v) {
    _position += v;
}

void Transform::rotateLocal(float degrees) {
    _localRotation += degrees;
}

void Transform::rotateGlobal(float degrees) {
    _globalRotation += degrees;
}

glm::vec3 Transform::getInitialPosition() {
    return _position;
}

glm::vec3 Transform::getPosition() const {
    glm::vec4 transformedPosition = _calculateModelMatrix() * glm::vec4(0.0f, 0.0f, 0.0f, 1.0f);
    return glm::vec3(transformedPosition.x, transformedPosition.y, transformedPosition.z);
}

glm::vec3 Transform::getScale() const {
    return _scale;
}

void Transform::passModelMatrixToShader() {
    glm::mat4 modelMatrix = _calculateModelMatrix();

    // Apply model transformation matrix
    ShaderContainer::instance()->setModelMatrix(&modelMatrix[0][0]);
}

glm::mat4 Transform::_calculateModelMatrix() const {
    glm::mat4 scaleMatrix          = glm::scale(_scale);
    glm::mat4 localRotationMatrix  = glm::rotate(_localRotation, glm::vec3(0.0f, 0.0f, 1.0f));
    glm::mat4 translateMatrix      = glm::translate(_position);
    glm::mat4 globalRotationMatrix = glm::rotate(_globalRotation, glm::vec3(0.0f, 0.0f, 1.0f));

    return globalRotationMatrix * translateMatrix * localRotationMatrix * scaleMatrix;
}
