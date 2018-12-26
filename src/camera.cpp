#include "camera.hpp"

#include <glm/gtc/matrix_transform.hpp>

Camera::Camera() {
    // Get current shader ID
    glGetIntegerv(GL_CURRENT_PROGRAM, &_shader);

    // Set initial values in shader
    _configureShader();
}

Camera::~Camera() {
    // Empty virtual destructor
}

void Camera::set(glm::vec3 position, glm::vec3 direction, glm::vec3 up) {
    _cameraPosition  = position;
    _cameraDirection = direction;
    _cameraUp        = up;

    _configureShader();
}

void Camera::update(int t) {
    // Check if camera has been changed this frame
    if (_update(t)) {
        // Set values in shader
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
    _viewMatrix = glm::lookAt(_cameraPosition, _cameraPosition + _cameraDirection, _cameraUp);
    glUniformMatrix4fv(viewMatrix, 1, GL_FALSE, &_viewMatrix[0][0]);
}
