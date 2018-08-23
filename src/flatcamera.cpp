#include "flatcamera.hpp"

FlatCamera::FlatCamera(GLuint shader) : Camera(shader) {
}

bool FlatCamera::_handleInput(SDL_Event event) {
    switch (event.type) {
        case SDL_KEYDOWN:
            switch (event.key.keysym.sym) {
                case SDLK_w:
                    _cameraPosition += glm::vec3(0.0f, 0.1f, 0.0f);
                    return true;
                case SDLK_s:
                    _cameraPosition += glm::vec3(0.0f, -0.1f, 0.0f);
                    return true;
                case SDLK_a:
                    _cameraPosition += glm::vec3(-0.1f, 0.0f, 0.0f);
                    return true;
                case SDLK_d:
                    _cameraPosition += glm::vec3(0.1f, 0.0f, 0.0f);
                    return true;
            }
    }
    return false;
}
