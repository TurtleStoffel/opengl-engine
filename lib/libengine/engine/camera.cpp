#include "camera.hpp"

#include "engine/shaders/shadercontainer.hpp"

#define GLM_ENABLE_EXPERIMENTAL
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtx/transform.hpp>

auto Camera::setWindowSize(int windowWidth, int windowHeight) -> void {
    m_windowWidth  = windowWidth;
    m_windowHeight = windowHeight;

    glViewport(0, 0, m_windowWidth, m_windowHeight);

    m_dirty = true;
}

auto Camera::calculateClickRay(int x, int y, glm::vec3& point, glm::vec3& direction) -> void {
    // Y coord is inverted in OpenGL
    int transformedY = m_windowHeight - y;

    // Transform coordinates to world space
    glm::vec3 nearPoint = glm::unProject(glm::vec3(x, transformedY, 0.0f),
                                         m_viewMatrix,
                                         m_projectionMatrix,
                                         glm::vec4(0.0, 0.0, m_windowWidth, m_windowHeight));

    // Transform coordinates of far off point to calculate direction
    glm::vec3 farPoint = glm::unProject(glm::vec3(x, transformedY, 1.0f),
                                        m_viewMatrix,
                                        m_projectionMatrix,
                                        glm::vec4(0.0, 0.0, m_windowWidth, m_windowHeight));

    point     = nearPoint;
    direction = farPoint - nearPoint;
}

auto Camera::handleInput(SDL_Event event) -> bool {
    bool handled = false;

    switch (event.type) {
        case SDL_KEYDOWN:
            switch (event.key.keysym.sym) {
                case SDLK_w:
                    m_wPressed = true;
                    handled    = true;
                    break;
                case SDLK_a:
                    m_aPressed = true;
                    handled    = true;
                    break;
                case SDLK_s:
                    m_sPressed = true;
                    handled    = true;
                    break;
                case SDLK_d:
                    m_dPressed = true;
                    handled    = true;
                    break;
            }
            break;
        case SDL_KEYUP:
            switch (event.key.keysym.sym) {
                case SDLK_w:
                    m_wPressed = false;
                    handled    = true;
                    break;
                case SDLK_a:
                    m_aPressed = false;
                    handled    = true;
                    break;
                case SDLK_s:
                    m_sPressed = false;
                    handled    = true;
                    break;
                case SDLK_d:
                    m_dPressed = false;
                    handled    = true;
                    break;
            }
            break;
    }

    return handled;
}

auto Camera::update(int dt, const ShaderContainer& shaderContainer) -> void {
    moveFlat(dt);

    if (m_dirty) {
        // Update shaders if camera has been changed
        configureShader(shaderContainer);
    }
}

auto Camera::configureShader(const ShaderContainer& shaderContainer) -> void {
    shaderContainer.lowPolyShader().setCameraPosition(&m_cameraPosition[0]);

    // calculate projection and view matrix
    auto ratio         = (float)m_windowWidth / m_windowHeight;
    m_projectionMatrix = glm::ortho(-5.0f * ratio, 5.0f * ratio, -5.0f, 5.0f, 0.1f, 100.0f);

    m_viewMatrix = glm::lookAt(m_cameraPosition, m_cameraPosition + CAMERA_DIRECTION, CAMERA_UP);

    // Set matrix values in shaders
    shaderContainer.setViewProjectionMatrix(&m_viewMatrix[0][0], &m_projectionMatrix[0][0]);

    m_dirty = false;
}

auto Camera::moveFlat(int dt) -> void {
    glm::vec3 direction = glm::vec3(0.0f, 0.0f, 0.0f);

    if (m_wPressed) {
        direction += glm::vec3(0.0f, 1.0f, 0.0f);
    }
    if (m_aPressed) {
        direction += glm::vec3(-1.0f, 0.0f, 0.0f);
    }
    if (m_sPressed) {
        direction += glm::vec3(0.0f, -1.0f, 0.0f);
    }
    if (m_dPressed) {
        direction += glm::vec3(1.0f, 0.0f, 0.0f);
    }

    // Only update camera if direction is not zero
    if (glm::length(direction) > 0.0f) {
        m_cameraPosition += glm::normalize(direction) * SPEED * ((float)dt);
        m_dirty = true;
    }
}