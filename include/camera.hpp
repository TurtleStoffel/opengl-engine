#ifndef CAMERA_HPP
#define CAMERA_HPP

#include <glm/glm.hpp>

#include "opengl.hpp"
#include "updateable.hpp"

class Camera : public Updateable {
   public:
    Camera(GLuint shader);
    virtual ~Camera();

    virtual void handleInput(SDL_Event event) = 0;

    // Updateable Interface
    virtual void update(int t);

   protected:
    virtual bool _update(int t) = 0;

    glm::vec3 _cameraPosition  = glm::vec3(0.0f, -5.0f, 10.0f);
    glm::vec3 _cameraDirection = glm::vec3(0.0f, 0.8f, -1.0f);
    glm::vec3 _cameraUp        = glm::vec3(0.0f, 1.0f, 0.0f);

    bool _wPressed = false;
    bool _aPressed = false;
    bool _sPressed = false;
    bool _dPressed = false;

   private:
    void _configureShader();
    GLuint _shader;
};

#endif
