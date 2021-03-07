#include "engine/objects/transform.hpp"

#include "engine/shaders/shadercontainer.hpp"

#define GLM_ENABLE_EXPERIMENTAL
#include <glm/gtx/transform.hpp>

void Transform::scale(glm::vec3 v) {
    _scale *= v;
}

void Transform::translate(glm::vec3 v) {
    _position += v;
}

void Transform::rotateLocal(float radians) {
    _localRotation += radians;
}

void Transform::rotateGlobal(float radians) {
    _globalRotation += radians;
}

glm::vec3 Transform::getPosition() const {
    glm::vec4 transformedPosition = calculateModelMatrix() * glm::vec4(0.0f, 0.0f, 0.0f, 1.0f);
    return glm::vec3(transformedPosition.x, transformedPosition.y, transformedPosition.z);
}

glm::vec3 Transform::getScale() const {
    return _scale;
}

void Transform::passModelMatrixToShader(const ShaderRegistry& shaderContainer) const {
    glm::mat4 modelMatrix = calculateModelMatrix();

    // Apply model transformation matrix
    shaderContainer.setModelMatrix(&modelMatrix[0][0]);
}

glm::mat4 Transform::calculateModelMatrix() const {
    glm::mat4 scaleMatrix          = glm::scale(_scale);
    glm::mat4 localRotationMatrix  = glm::rotate(_localRotation, glm::vec3(0.0f, 0.0f, 1.0f));
    glm::mat4 translateMatrix      = glm::translate(_position);
    glm::mat4 globalRotationMatrix = glm::rotate(_globalRotation, glm::vec3(0.0f, 0.0f, 1.0f));

    glm::mat4 modelMatrix = globalRotationMatrix * translateMatrix * localRotationMatrix *
                            scaleMatrix;

    if (parent) {
        modelMatrix = parent->calculateModelMatrix() * modelMatrix;
    }

    return modelMatrix;
}
