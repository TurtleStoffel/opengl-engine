#include "flatcamera.hpp"

#include "glm/gtc/epsilon.hpp"

FlatCamera::~FlatCamera() {
    // Empty virtual destructor
}

bool FlatCamera::_update(int t) {
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

    // Only update camera if direction is not zero
    if (glm::length(direction) > 0.0f) {
        _cameraPosition += glm::normalize(direction) * _speed * ((float)t);
        return true;
    } else {
        return false;
    }
}

bool FlatCamera::handleInput(SDL_Event event) {
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
            }
            break;
    }

    return handled;
}

FlatCamera::FlatCamera() {
    // Empty private constructor
}

Camera* FlatCamera::changeInstance() {
    // There is already an instance of the camera
    if (_pCamera) {
        delete _pCamera;
    }

    _pCamera = new FlatCamera();

    return Camera::_pCamera;
}
