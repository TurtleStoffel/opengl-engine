#pragma once

#include "engine/application.hpp"

namespace Godworld {
    class GameApplication : public Application {
      public:
        GameApplication(SDL_Window* pWindow);
        ~GameApplication() override = default;

      protected:
        virtual void _createScene();
    };
}