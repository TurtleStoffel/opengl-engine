#include "application.hpp"

#include "scene/scene.hpp"

#include <memory>

namespace ModelEditor {
    Application::Application(SDL_Window& window)
          : Engine::Application{window} {
        m_scene = std::make_unique<Scene>(m_shaderRegistry);
    }
}