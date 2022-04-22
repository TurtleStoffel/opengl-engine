#pragma once

#include "engine/application.hpp"

namespace ModelEditor {
    class Application : public Engine::Application {
      public:
        Application(SDL_Window& window);
        ~Application() override = default;
    };
}