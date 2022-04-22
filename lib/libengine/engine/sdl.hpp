#pragma once

#include "engine/opengl.hpp"

#include <memory>
#include <string>
#include <time.h>

namespace Engine {
    class SDL {
      public:
        template <typename TApplication>
        static auto startApplication(const std::string& name) -> void;

      private:
        static auto createWindow(const std::string& name) -> SDL_Window*;
        static auto destroy(SDL_Window* window) -> void;
    };

    template <typename TApplication>
    auto SDL::startApplication(const std::string& name) -> void {
        auto window = Engine::SDL::createWindow(name);

        // set random seed
        srand(time(NULL));

        auto application = std::make_unique<TApplication>(*window);
        application->run();

        Engine::SDL::destroy(window);
    }
}