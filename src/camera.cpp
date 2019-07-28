#include "camera.hpp"

#include <glm/gtc/matrix_transform.hpp>

#include "const.hpp"
#include "shadercontainer.hpp"

Camera::Camera(glm::vec3 position, glm::vec3 direction, glm::vec3 up, MovementMode movementMode) {
    // Set initial window size
    _windowWidth  = constant::initialWindowWidth;
    _windowHeight = constant::initialWindowHeight;

    _movementMode = movementMode;

    // TODO update this to 'position', 'target' and calculate 'up' from that in US-21
    _cameraPosition  = position;
    _cameraDirection = direction;
    _cameraUp        = up;

    // Set initial values in shader
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
    // Y coord is inverted in OpenGL
    int transformedY = _windowHeight - y;

    // Transform coordinates to world space
    glm::vec3 nearPoint = glm::unProject(glm::vec3(x, transformedY, 0.0f),
                                         _viewMatrix,
                                         _projectionMatrix,
                                         glm::vec4(0.0, 0.0, _windowWidth, _windowHeight));

    // Transform coordinates of far off point to calculate direction
    glm::vec3 farPoint = glm::unProject(glm::vec3(x, transformedY, 1.0f),
                                        _viewMatrix,
                                        _projectionMatrix,
                                        glm::vec4(0.0, 0.0, _windowWidth, _windowHeight));

    point     = nearPoint;
    direction = farPoint - nearPoint;
}

bool Camera::handleInput(SDL_Event event) {
    bool handled = false;

    switch (event.type) {
        case SDL_KEYDOWN:
            switch (event.key.keysym.sym) {
                case SDLK_w:
                    _wPressed = true;
                    handled   = true;
                    break;
                case SDLK_a:
                    _aPressed = true;
                    handled   = true;
                    break;
                case SDLK_s:
                    _sPressed = true;
                    handled   = true;
                    break;
                case SDLK_d:
                    _dPressed = true;
                    handled   = true;
                    break;
                case SDLK_q:
                    _qPressed = true;
                    handled   = true;
                    break;
                case SDLK_e:
                    _ePressed = true;
                    handled   = true;
                    break;
            }
            break;
        case SDL_KEYUP:
            switch (event.key.keysym.sym) {
                case SDLK_w:
                    _wPressed = false;
                    handled   = true;
                    break;
                case SDLK_a:
                    _aPressed = false;
                    handled   = true;
                    break;
                case SDLK_s:
                    _sPressed = false;
                    handled   = true;
                    break;
                case SDLK_d:
                    _dPressed = false;
                    handled   = true;
                    break;
                case SDLK_q:
                    _qPressed = false;
                    handled   = true;
                    break;
                case SDLK_e:
                    _ePressed = false;
                    handled   = true;
                    break;
            }
            break;
    }

    return handled;
}

void Camera::update(int dt) {
    bool updated = false;
    // Call the correct update method according to MovementMode
    switch (_movementMode) {
        case FLAT:
            updated = _moveFlat(dt);
            break;
        case SPHERICAL:
            updated = _moveSpherical(dt);
            break;
    }

    // If camera has been changed this frame, update the shaders
    if (updated) {
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
    ShaderContainer::instance()->setViewProjectionMatrix(&_viewMatrix[0][0],
                                                         &_projectionMatrix[0][0]);
}

bool Camera::_moveFlat(int dt) {
    glm::vec3 direction = glm::vec3(0.0f, 0.0f, 0.0f);

    if (_wPressed) {
        direction += glm::vec3(0.0f, 1.0f, 0.0f);
    }
    if (_aPressed) {
        direction += glm::vec3(-1.0f, 0.0f, 0.0f);
    }
    if (_sPressed) {
        direction += glm::vec3(0.0f, -1.0f, 0.0f);
    }
    if (_dPressed) {
        direction += glm::vec3(1.0f, 0.0f, 0.0f);
    }
    if (_qPressed) {
        direction += glm::vec3(0.0f, 0.0f, 1.0f);
    }
    if (_ePressed) {
        direction += glm::vec3(0.0f, 0.0f, -1.0f);
    }

    // Only update camera if direction is not zero
    if (glm::length(direction) > 0.0f) {
        _cameraPosition += glm::normalize(direction) * _speed * ((float)dt);
        return true;
    } else {
        return false;
    }
}

bool Camera::_moveSpherical(int dt) {
    // TODO to be implemented in US-16
    return false;
}
