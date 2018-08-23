#ifndef CAMERA_HPP
#define CAMERA_HPP

#include <glm/glm.hpp>

#include "opengl.hpp"

class Camera {
   public:
    Camera(GLuint shader);
    void handleInput(SDL_Event event);

   protected:
    virtual bool _handleInput(SDL_Event event) = 0;

    glm::vec3 _cameraPosition  = glm::vec3(0.0f, -5.0f, 10.0f);
    glm::vec3 _cameraDirection = glm::vec3(0.0f, 0.8f, -1.0f);
    glm::vec3 _cameraUp        = glm::vec3(0.0f, 1.0f, 0.0f);

   private:
    void _configureShader();
    GLuint _shader;
};

#endif
