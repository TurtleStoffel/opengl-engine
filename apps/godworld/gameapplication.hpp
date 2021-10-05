#pragma once

#include "engine/application.hpp"

namespace Godworld {
    class GameApplication : public Engine::Application {
      public:
        GameApplication(SDL_Window* pWindow);
        ~GameApplication() override = default;
    };
}