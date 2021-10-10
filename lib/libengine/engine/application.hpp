#pragma once

#include "engine/scene.hpp"
#include "engine/shaderregistry.hpp"

#include <SDL2/SDL.h>
#include <memory>

struct SDL_Window;

namespace Engine {
    class Application {
      public:
        /**
         * Constructor can only be called once in the entire program, otherwise will throw error
         */
        Application(SDL_Window* pWindow);
        virtual ~Application() = default;

        void run();

      protected:
        ShaderRegistry m_shaderRegistry;

        std::unique_ptr<Engine::Scene> m_scene;

      private:
        auto handleInput() -> void;
        auto updateScene() -> void;
        auto renderScene() -> void;
        auto throttleFps() -> void;

        auto getTicksSinceLastUpdate() -> int;
        auto handleApplicationInput(SDL_Event event) -> bool;

        bool m_running{true};
        int m_lastFpsTicks;
        int m_lastUpdateTicks;

        SDL_Window* m_window;
    };
}