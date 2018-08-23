#include "camera.hpp"

#include <glm/gtc/matrix_transform.hpp>

Camera::Camera(GLuint shader) {
    _shader = shader;
    _configureShader();
}

void Camera::handleInput(SDL_Event event) {
    if (_handleInput(event)) {
        _configureShader();
    }
}

void Camera::_configureShader() {
    // Get uniform locations
    GLuint viewMatrix           = glGetUniformLocation(_shader, "view");
    GLuint shaderCameraPosition = glGetUniformLocation(_shader, "cameraPosition");

    // Set camera position
    glUniform3fv(shaderCameraPosition, 1, &_cameraPosition[0]);

    // Set camera view matrix
    glm::mat4 view = glm::lookAt(_cameraPosition, _cameraPosition + _cameraDirection, _cameraUp);
    glUniformMatrix4fv(viewMatrix, 1, GL_FALSE, &view[0][0]);
}
