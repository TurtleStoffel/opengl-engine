#include "flatcamera.hpp"

FlatCamera::~FlatCamera() {
    // Empty virtual destructor
}

bool FlatCamera::_update(int t) {
    if (_wPressed) {
        _cameraPosition += glm::vec3(0.0f, 0.01f, 0.0f) * ((float)t);
    }
    if (_aPressed) {
        _cameraPosition += glm::vec3(-0.01f, 0.0f, 0.0f) * ((float)t);
    }
    if (_sPressed) {
        _cameraPosition += glm::vec3(0.0f, -0.01f, 0.0f) * ((float)t);
    }
    if (_dPressed) {
        _cameraPosition += glm::vec3(0.01f, 0.0f, 0.0f) * ((float)t);
    }
    return (_wPressed || _aPressed || _sPressed || _dPressed);
}

void FlatCamera::handleInput(SDL_Event event) {
    switch (event.type) {
        case SDL_KEYDOWN:
            switch (event.key.keysym.sym) {
                case SDLK_w:
                    _wPressed = true;
                    break;
                case SDLK_a:
                    _aPressed = true;
                    break;
                case SDLK_s:
                    _sPressed = true;
                    break;
                case SDLK_d:
                    _dPressed = true;
                    break;
            }
            break;
        case SDL_KEYUP:
            switch (event.key.keysym.sym) {
                case SDLK_w:
                    _wPressed = false;
                    break;
                case SDLK_a:
                    _aPressed = false;
                    break;
                case SDLK_s:
                    _sPressed = false;
                    break;
                case SDLK_d:
                    _dPressed = false;
                    break;
            }
            break;
    }
}

FlatCamera::FlatCamera() {
    // Empty private constructor
}

Camera* FlatCamera::changeInstance() {
    _pCamera = new FlatCamera();

    return Camera::_pCamera;
}
