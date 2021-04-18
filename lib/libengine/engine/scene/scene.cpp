#include "engine/scene/scene.hpp"

#include "engine/application.hpp"
#include "engine/camera.hpp"
#include "engine/components/collider.hpp"

#include <glm/gtc/matrix_transform.hpp>

Scene::Scene(const ShaderRegistry& shaderRegistry)
      : m_camera{std::make_unique<Camera>()}
      , m_guiFactory{GuiFactory{GuiFactory::GuiType::GAME}}
      , m_shaderRegistry{shaderRegistry} {
}

auto Scene::update(int dt) -> void {
    m_camera->update(dt, m_shaderRegistry);

    for (auto& pObject : m_objects) {
        pObject->update(dt);
    }
}

auto Scene::render() -> void {
    for (auto& pObject : m_objects) {
        pObject->render(m_shaderRegistry);
    }

    renderGui();
}

auto Scene::handleInput(SDL_Event event) -> bool {
    if (m_camera->handleInput(event)) {
        return true;
    }

    // Mousepicking has no impact on return value
    mousePick(event);

    return false;
}

auto Scene::setWindowSize(int windowWidth, int windowHeight) -> void {
    m_camera->setWindowSize(windowWidth, windowHeight);
}

auto Scene::renderGui() -> void {
}

auto Scene::mousePick(SDL_Event event) -> void {
    // Only update if mouse has moved
    if (event.type == SDL_MOUSEMOTION) {
        // Transform point to ray in world space
        glm::vec3 point;
        glm::vec3 direction;
        m_camera->calculateClickRay(event.motion.x, event.motion.y, point, direction);

        // Check for each object in scene if there was an intersection
        for (auto& entity : m_objects) {
            auto collider = entity->get<Engine::Components::Collider>();
            if (collider) {
                collider->intersect(point, direction);
            }
        }
    }
}