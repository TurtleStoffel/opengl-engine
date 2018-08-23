#include "flatcamera.hpp"

FlatCamera::FlatCamera(GLuint shader) : Camera(shader) {
}

bool FlatCamera::_update() {
    if (_wPressed) {
        _cameraPosition += glm::vec3(0.0f, 0.1f, 0.0f);
    }
    if (_aPressed) {
        _cameraPosition += glm::vec3(-0.1f, 0.0f, 0.0f);
    }
    if (_sPressed) {
        _cameraPosition += glm::vec3(0.0f, -0.1f, 0.0f);
    }
    if (_dPressed) {
        _cameraPosition += glm::vec3(0.1f, 0.0f, 0.0f);
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
