#include "camera.hpp"

#include <glm/gtc/matrix_transform.hpp>

#include "const.hpp"
#include "shadercontainer.hpp"

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

    _configureShader();
}

void Camera::getWindowSize(int& windowWidth, int& windowHeight) {
    windowWidth  = _windowWidth;
    windowHeight = _windowHeight;
}

void Camera::calculateClickRay(int x, int y, glm::vec3& point, glm::vec3& direction) {
    // Transform coordinates to world space
    glm::vec3 nearPoint = glm::unProject(glm::vec3(x, y, 0.0),
                                         _viewMatrix,
                                         _projectionMatrix,
                                         glm::vec4(0.0, 0.0, _windowWidth, _windowHeight));

    // Transform coordinates of far off point to calculate direction
    glm::vec3 farPoint = glm::unProject(glm::vec3(x, y, 1.0),
                                        _viewMatrix,
                                        _projectionMatrix,
                                        glm::vec4(0.0, 0.0, _windowWidth, _windowHeight));

    point     = nearPoint;
    direction = farPoint - nearPoint;
}

void Camera::update(int t) {
    // Check if camera has been changed this frame
    if (_update(t)) {
        // Set values in shader
        _configureShader();
    }
}

void Camera::_configureShader() {
    // Set camera position
    ShaderContainer::instance()->lowPolyShader()->setUniform3fv("cameraPosition",
                                                                &_cameraPosition[0]);

    // calculate projection and view matrix
    _projectionMatrix = glm::perspective(glm::radians(45.0f),
                                         (float)_windowWidth / _windowHeight,
                                         0.1f,
                                         100.0f);

    _viewMatrix = glm::lookAt(_cameraPosition, _cameraPosition + _cameraDirection, _cameraUp);

    // Set matrix values in shaders
    ShaderContainer::instance()->setModelViewProjectionMatrix(nullptr,
                                                              &_viewMatrix[0][0],
                                                              &_projectionMatrix[0][0]);
}
