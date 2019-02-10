#ifndef CAMERA_HPP
#define CAMERA_HPP

#include <glm/glm.hpp>

#include "opengl.hpp"

#include "interfaces/updateable.hpp"

class Camera : public Updateable {
   public:
    /**
     * Destructor has to be public to allow child classes to delete singleton instance
     */
    virtual ~Camera();

    /**
     * Request current singleton instance
     */
    static Camera* instance();

    /**
     * Set parameters of camera
     */
    void set(glm::vec3 position, glm::vec3 direction, glm::vec3 up);

    void setWindowSize(int windowWidth, int windowHeight);
    void getWindowSize(int& windowWidth, int& windowHeight);

    /**
     * Calculate ray when clicking on point (x,y) on the screen
     * return output in point and direction parameters
     */
    void calculateClickRay(int x, int y, glm::vec3& point, glm::vec3& direction);

    /**
     * Abstract class to force child classes to implement handleInput
     * Return true if input has been handled by the camera
     */
    virtual bool handleInput(SDL_Event event) = 0;

    /**
     * Updateable Interface methods
     */
    virtual void update(int t);

   protected:
    // Singleton class
    Camera();

    static Camera* _pCamera;

    virtual bool _update(int t) = 0;

    /**
     * Camera parameters
     */
    glm::vec3 _cameraPosition  = glm::vec3(0.0f, 0.0f, 5.0f);
    glm::vec3 _cameraDirection = glm::vec3(0.0f, 0.0f, -1.0f);
    glm::vec3 _cameraUp        = glm::vec3(0.0f, 1.0f, 0.0f);

    /**
     * Camera movement parameters
     */
    bool _wPressed = false;
    bool _aPressed = false;
    bool _sPressed = false;
    bool _dPressed = false;

   private:
    /**
     * Calculate _projectionMatrix/_viewMatrix and set shader uniforms
     */
    void _configureShader();

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
