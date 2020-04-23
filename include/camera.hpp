#ifndef CAMERA_HPP
#define CAMERA_HPP

#include <glm/glm.hpp>

#include "interfaces/updateable.hpp"
#include "opengl.hpp"

class Camera : public Updateable {
  public:
    enum MovementMode { FLAT, SPHERICAL };

    /**
     * Camera is first initialized in the Application where the Scene is not known yet. The Scene
     * is repsonsible to actually set the values in the Camera according to what is needed (using
     * the set-method)
     */
    Camera();
    virtual ~Camera();

    void setOrientation(glm::vec3 position, glm::vec3 target, glm::vec3 up);

    void setFlatMovement();
    void setSphericalMovement(float distance);

    void setWindowSize(int windowWidth, int windowHeight);
    void getWindowSize(int& windowWidth, int& windowHeight);

    /**
     * Calculate ray when clicking on point (x,y) on the screen
     * return output in point and direction parameters
     */
    void calculateClickRay(int x, int y, glm::vec3& point, glm::vec3& direction);

    /**
     * Checks if any of the relevant keys for the Camera have been pressed. Returns True if input
     * has been handled
     */
    bool handleInput(SDL_Event event);

    /**
     * Updateable Interface methods
     */
    virtual void update(int dt);

  private:
    /**
     * Calculate _projectionMatrix/_viewMatrix and set shader uniforms
     */
    void _configureShader();

    /**
     * Movement methods that will be called depending on _movementMode
     */
    bool _moveFlat(int dt);
    bool _moveSpherical(int dt);

    /**
     * Camera parameters
     * Vectors are normalized
     */
    glm::vec3 _cameraPosition  = glm::vec3(0.0f, 0.0f, 5.0f);
    glm::vec3 _cameraDirection = glm::vec3(0.0f, 0.0f, -1.0f);
    glm::vec3 _cameraUp        = glm::vec3(0.0f, 1.0f, 0.0f);

    /**
     * Variables to track key presses
     */
    bool _wPressed = false;
    bool _aPressed = false;
    bool _sPressed = false;
    bool _dPressed = false;
    bool _qPressed = false;
    bool _ePressed = false;

    /**
     * Determines how the camera moves in the _update call
     */
    MovementMode _movementMode;
    const float _speed = 0.001f;

    /**
     * Parameters required for Spherical Movement (around a target from a specific distance)
     */
    glm::vec3 _target;
    float _distance;

    /**
     * Window Size
     */
    int _windowWidth;
    int _windowHeight;

    /**
     * OpenGL matrices
     */
    glm::mat4 _viewMatrix;
    glm::mat4 _projectionMatrix;
};

#endif
