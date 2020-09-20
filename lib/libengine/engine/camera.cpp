#include "camera.hpp"

#include <math.h>

#define GLM_ENABLE_EXPERIMENTAL
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtx/transform.hpp>

#include "shadercontainer.hpp"

void Camera::setOrientation(glm::vec3 position, glm::vec3 target, glm::vec3 up) {
    _cameraPosition  = position;
    _cameraDirection = glm::normalize(target - position);
    _cameraUp        = glm::normalize(up);

    // For Spherical Movement
    _target = target;

    dirty = true;
}

void Camera::setFlatMovement() {
    _movementMode = FLAT;
}

void Camera::setSphericalMovement(float distance) {
    _movementMode = SPHERICAL;

    _distance = distance;
}

void Camera::setWindowSize(int windowWidth, int windowHeight) {
    this->windowWidth  = windowWidth;
    this->windowHeight = windowHeight;

    glViewport(0, 0, windowWidth, windowHeight);

    dirty = true;
}

void Camera::getWindowSize(int& windowWidth, int& windowHeight) {
    windowWidth  = this->windowWidth;
    windowHeight = this->windowHeight;
}

void Camera::calculateClickRay(int x, int y, glm::vec3& point, glm::vec3& direction) {
    // Y coord is inverted in OpenGL
    int transformedY = windowHeight - y;

    // Transform coordinates to world space
    glm::vec3 nearPoint = glm::unProject(glm::vec3(x, transformedY, 0.0f),
                                         _viewMatrix,
                                         _projectionMatrix,
                                         glm::vec4(0.0, 0.0, windowWidth, windowHeight));

    // Transform coordinates of far off point to calculate direction
    glm::vec3 farPoint = glm::unProject(glm::vec3(x, transformedY, 1.0f),
                                        _viewMatrix,
                                        _projectionMatrix,
                                        glm::vec4(0.0, 0.0, windowWidth, windowHeight));

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

void Camera::update(int dt, const ShaderContainer& shaderContainer) {
    // Call the correct update method according to MovementMode
    switch (_movementMode) {
        case FLAT:
            moveFlat(dt);
            break;
        case SPHERICAL:
            moveSpherical(dt);
            break;
    }

    // If camera has been changed this frame, update the shaders
    if (dirty) {
        // Set values in shader
        configureShader(shaderContainer);
    }
}

void Camera::configureShader(const ShaderContainer& shaderContainer) {
    // Set camera position
    shaderContainer.getLowPolyShader()->setUniform3fv("cameraPosition", &_cameraPosition[0]);

    // calculate projection and view matrix
    _projectionMatrix = glm::perspective(glm::radians(45.0f),
                                         (float)windowWidth / windowHeight,
                                         0.1f,
                                         100.0f);

    _viewMatrix = glm::lookAt(_cameraPosition, _cameraPosition + _cameraDirection, _cameraUp);

    // Set matrix values in shaders
    shaderContainer.setViewProjectionMatrix(&_viewMatrix[0][0], &_projectionMatrix[0][0]);

    dirty = false;
}

void Camera::moveFlat(int dt) {
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
        dirty = true;
    }
}

void Camera::moveSpherical(int dt) {
    glm::vec3 direction = glm::vec3(0.0f, 0.0f, 0.0f);

    // Cross Product of normalized Vectors is generally not a normalized vector
    glm::vec3 right = glm::normalize(glm::cross(_cameraDirection, _cameraUp));

    glm::vec3 originalCameraDirection = _cameraDirection;

    if (_wPressed) {
        direction += _cameraUp;
    }
    if (_aPressed) {
        direction += -right;
    }
    if (_sPressed) {
        direction += -_cameraUp;
    }
    if (_dPressed) {
        direction += right;
    }

    if (glm::length(direction) > 0.0f) {
        // Camera has moved, calculate new position
        _cameraPosition += glm::normalize(direction) * _speed * ((float)dt);
        // Update orientation so it points towards target and is at correct distance
        // Unit Vector from updated Position to target
        glm::vec3 v = glm::normalize(_cameraPosition - _target);
        // Move Camera Position to correct distance from the target
        _cameraPosition  = _target + v * _distance;
        _cameraDirection = -v;

        // TODO Bugfix this implementation in US-29
        // Get Vector Perpendicular to the Vector Rotation
        glm::vec3 rotationAxis = glm::normalize(
            glm::cross(_cameraDirection, originalCameraDirection));
        // Get angle that Vector rotated from original to new direction
        float rotationAngle = acos(glm::dot(_cameraDirection, originalCameraDirection));
        // Check if rotation axis and angle is valid
        if (!glm::isnan(rotationAngle) && !glm::all(glm::isnan(rotationAxis))) {
            // Calculate Rotation Matrix
            glm::mat4 rotationMatrix = glm::rotate(rotationAngle, rotationAxis);

            // Transform Camera Up Vector
            glm::vec4 transformedUp = rotationMatrix *
                                      glm::vec4(_cameraUp.x, _cameraUp.y, _cameraUp.z, 0.0f);
            _cameraUp = glm::normalize(
                glm::vec3(transformedUp.x, transformedUp.y, transformedUp.z));
        }

        dirty = true;
    }
}
