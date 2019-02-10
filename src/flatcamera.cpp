#include "flatcamera.hpp"

FlatCamera::~FlatCamera() {
    // Empty virtual destructor
}

bool FlatCamera::_update(int t) {
    if (_wPressed) {
        _cameraPosition += glm::vec3(0.0f, _speed, 0.0f) * ((float)t);
    }
    if (_aPressed) {
        _cameraPosition += glm::vec3(-_speed, 0.0f, 0.0f) * ((float)t);
    }
    if (_sPressed) {
        _cameraPosition += glm::vec3(0.0f, -_speed, 0.0f) * ((float)t);
    }
    if (_dPressed) {
        _cameraPosition += glm::vec3(_speed, 0.0f, 0.0f) * ((float)t);
    }
    return (_wPressed || _aPressed || _sPressed || _dPressed);
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
