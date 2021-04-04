#include "gameapplication.hpp"

#include "scene/systemscene.hpp"

namespace Godworld {
    GameApplication::GameApplication(SDL_Window* window)
          : Application{window} {
    }

    void GameApplication::_createScene() {
        m_scene = std::make_unique<SystemScene>(m_shaderRegistry);
    }
}