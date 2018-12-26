#include "camera.hpp"

#include <glm/gtc/matrix_transform.hpp>

#include "const.hpp"

Camera* Camera::_pCamera = nullptr;

Camera* Camera::instance() {
    // There should always be an instance of the camera when requesting it
    assert(_pCamera);

    // Return current instance
    return _pCamera;
}

Camera::Camera() {
    // Set initial window size
    _windowWidth  = constant::initialWindowWidth;
    _windowHeight = constant::initialWindowHeight;

    // Set _shader member to current active Shader
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

void Camera::setWindowSize(int windowWidth, int windowHeight) {
    _windowWidth  = windowWidth;
    _windowHeight = windowHeight;

    glViewport(0, 0, _windowWidth, _windowHeight);
}

void Camera::getWindowSize(int& windowWidth, int& windowHeight) {
    windowWidth  = _windowWidth;
    windowHeight = _windowHeight;
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
    GLuint shaderCameraPosition = glGetUniformLocation(_shader, "cameraPosition");
    GLuint projectionMatrix     = glGetUniformLocation(_shader, "projection");
    GLuint viewMatrix           = glGetUniformLocation(_shader, "view");

    // Set camera position
    glUniform3fv(shaderCameraPosition, 1, &_cameraPosition[0]);

    // Set projection matrix
    _projectionMatrix = glm::perspective(glm::radians(45.0f),
                                         (float)_windowWidth / _windowHeight,
                                         0.1f,
                                         100.0f);
    glUniformMatrix4fv(projectionMatrix, 1, GL_FALSE, &_projectionMatrix[0][0]);

    // Set view matrix
    _viewMatrix = glm::lookAt(_cameraPosition, _cameraPosition + _cameraDirection, _cameraUp);
    glUniformMatrix4fv(viewMatrix, 1, GL_FALSE, &_viewMatrix[0][0]);
}
