#pragma once

#include "const.hpp"
#include "opengl.hpp"

#include <glm/glm.hpp>

class ShaderContainer;

class Camera {
  public:
    auto setWindowSize(int windowWidth, int windowHeight) -> void;

    /**
     * Calculate ray when clicking on point (x,y) on the screen
     * return output in point and direction parameters
     */
    auto calculateClickRay(int x, int y, glm::vec3& point, glm::vec3& direction) -> void;

    /**
     * Checks if any of the relevant keys for the Camera have been pressed. Returns True if input
     * has been handled
     */
    auto handleInput(SDL_Event event) -> bool;

    auto update(int dt, const ShaderContainer& shaderContainer) -> void;

  private:
    /**
     * Calculate _projectionMatrix/_viewMatrix and set shader uniforms
     */
    auto configureShader(const ShaderContainer& shaderContainer) -> void;

    auto moveFlat(int dt) -> void;

    glm::vec3 m_cameraPosition = glm::vec3(0.0f, 0.0f, 5.0f);

    static constexpr glm::vec3 CAMERA_DIRECTION = glm::vec3(0.0f, 0.0f, -1.0f);
    static constexpr glm::vec3 CAMERA_UP        = glm::vec3(0.0f, 1.0f, 0.0f);

    bool m_wPressed = false;
    bool m_aPressed = false;
    bool m_sPressed = false;
    bool m_dPressed = false;

    // Camera speed in the update call
    static constexpr float SPEED = 0.001f;

    int m_windowWidth  = constant::initialWindowWidth;
    int m_windowHeight = constant::initialWindowHeight;

    glm::mat4 m_viewMatrix;
    glm::mat4 m_projectionMatrix;

    bool m_dirty = true;
};